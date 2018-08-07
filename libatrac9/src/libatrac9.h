#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#define ATRAC9_CONFIG_DATA_SIZE 4

typedef struct {
	int channels;
	int channelConfigIndex;
	int samplingRate;
	int superframeSize;
	int framesInSuperframe;
	int frameSamples;
	int wlength;
	unsigned char configData[ATRAC9_CONFIG_DATA_SIZE];
} Atrac9CodecInfo;

typedef void* HANDLE_ATRAC9;

void* Atrac9GetHandle(void);
void Atrac9ReleaseHandle(void* handle);

int Atrac9InitDecoder(void* handle, unsigned char *pConfigData);
int Atrac9Decode(void* handle, const unsigned char *pAtrac9Buffer, void *pPcmBuffer, int *pNBytesUsed);

int Atrac9GetCodecInfo(void* handle, Atrac9CodecInfo *pCodecInfo);

#ifdef __cplusplus
}
#endif
