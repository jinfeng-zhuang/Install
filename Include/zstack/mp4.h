#ifndef ZSTACK_MP4_H
#define ZSTACK_MP4_H

#include "types.h"

typedef int (*mp4box_parser_func)(u8* buffer, u32 len, void *out);

#pragma pack(push, 1)
struct Box {
	u32 size;
	u32 type;
};

struct LargeBox {
	u32 size;
	u32 type;
	u64 large_size;
};

struct FullBox {
	struct Box box;
	u32 version_flag;
};

struct SampleEntry {
	struct Box box;
	u8 rsvd[6];
	u16 data_reference_index;
};

struct VisualSampleEntry {
	struct SampleEntry SE;

	u16 pre_defined;
	u16 rsvd;
	u32 pre_defined2[3];
	u16 width;
	u16 height;
	u32 horiz;
	u32 vert;
	u32 rsvd2;
	u16 frame_count;
	u8 compressorname[32];
	u16 depth;
	u16 pre_defined3;
};

struct AVCDecoderConfigurationRecord {
	u8 configurationVersion;
	u8 AVCProfileIndication;
	u8 profile_compatibility;
	u8 AVCLevelIndication;
	u8 reserved_6bits_111111;
	u8 lengthSizeMinusOne;
	u8 reserved_3bits_111;
	u8 numOfSequenceParameterSets;

	u16* sequenceParameterSetLength;
	u8** sequenceParameterSetNALUnit;

	u8 numOfPictureParameterSets;
	u16* pictureParameterSetLength;
	u8** pictureParameterSetNALUnit;

	u8 reserved_6bits_111111_2;
	u8 chroma_format;
	u8 reserved_5bits_11111;
	u8 bit_depth_luma_minus8;
	u8 reserved_5bits_11111_2;
	u8 bit_depth_chroma_minus8;
	u8 numOfSequenceParameterSetExt;

	u16* sequenceParameterSetExtLength;
	u8** sequenceParameterSetExtNALUnit;
};

struct AVCConfigurationBox {
	struct Box box;
	struct AVCDecoderConfigurationRecord AVCConfig;
};

struct AVCSampleEntry {
	struct VisualSampleEntry VSE;
	struct AVCConfigurationBox avc;
};

struct AudioSampleEntry {
	int entry_count;
};

struct HintSampleEntry {
	int entry_count;
};

struct SampleDescriptionBox {
	struct FullBox fullbox;
	int entry_count;
	//struct VisualSampleEntry  VSE;
	struct AVCSampleEntry AVC;
	struct AudioSampleEntry ASE;
	struct HintSampleEntry HSE;
};

struct MP4TrackHeader {
	struct FullBox fullbox;

	u32 creation_time;
	u32 modification_time;
	u32 track_id;
	u32 rsvd;
	u32 duration;

	u32 rsvd2[2];
	u16 layer;
	u16 group;
	u16 volumn;
	u16 rsvd3;
	u32 matrix[9];
	u32 width;
	u32 height;
};

struct MP4TrackHeaderV1 {
	struct FullBox fullbox;

	u64 creation_time;
	u64 modification_time;
	u32 track_id;
	u32 rsvd;
	u64 duration;

	u32 rsvd2[2];
	u16 layer;
	u16 group;
	u16 volumn;
	u16 rsvd3;
	u32 matrix[9];
	u32 width;
	u32 height;
};

#pragma pack(pop)

struct mp4box_parser {
	char type[5];
	mp4box_parser_func func;
};

struct mp4_box_stsd {
	int count;
	struct SampleDescriptionBox SampleDescBox;

	u16 sps_count;
	u16* sps_len;
	u8** sps;

	u16 pps_count;
	u16* pps_len;
	u8** pps;
};

struct mp4_box_stts {
	int entry_count;
	int *sample_count;
	int *sample_delta;
};

struct mp4_box_ctts {
	int entry_count;
	int *sample_count;
	int *sample_offset;
};

struct mp4_box_stss {
	int entry_count;
	int* sample_number;
};

struct MP4Info {
	struct mp4_box_stsd stsd;

	u16 sps_count;
	u16 *sps_len;
	u8** sps;

	u16 pps_count;
	u16 *pps_len;
	u8** pps;

	u8** sample;
	u32 * sample_len;
	u32 sample_count;

	u32 audio_sample_count;		// stsz
	u32 *audio_sample_offset;	// stco + stsc
	u32 *audio_sample_len;		// stsz
	u8** audio_sample;			// mdat
};

struct mp4_box_stsz {
	int sample_size;
	int sample_count;
	int* entry_size;
};

struct mp4_box_stco {
	int entry_count;
	int* chunk_offset;
};

struct mp4_box_stsc {
	int entry_count;
	int* first_chunk;
	int* sample_per_chunk;
	int* sample_desc_index;
};

struct MP4Chunk {
	struct mp4_box_stco stco;
	struct mp4_box_stsz stsz;
	struct mp4_box_stsc stsc;

	u32 count;
	u32* offset;
	u32* len;
	u32* data;
};

struct mp4_box_elst {
	int entry_count;
};

struct mp4_box_tkhd {
	u32 id;
	u32 duration;
	u32 volumn;
	u32 width;
	u32 height;
};

struct MP4Track {
	u32 id; // track id in tkhd
	u32 durationTrack;
	u32 width;
	u32 height;
	u32 volumn;

	struct mp4_box_elst elst;

	u32 timescale; // mdhd
	u32 durationMedia;
	u32 handle;

	struct mp4_box_stsd stsd;
	struct mp4_box_stts stts;
	struct mp4_box_ctts ctts;
	struct mp4_box_stss stss;
	struct mp4_box_stsc stsc;
	struct mp4_box_stsz stsz;
	struct mp4_box_stco stco;
};

extern RESULT mp4_box_scan(int depth, u8* buffer, u32 len);

extern int mp4_box_is_valid(u32 type);

#endif
