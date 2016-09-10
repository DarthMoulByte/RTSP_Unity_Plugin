#pragma once

#include "Unity/IUnityGraphics.h"
#include "RenderAPI.h"

#include "ffmpegenv.h"

#include "FFMpegStream.h"


namespace rtsp_unity_plugin {
	class FFMpegStream;
	class MediaSink;

	class FFMpegClass
	{

	private:
		FFMpegClass();
		~FFMpegClass();

	public:
		static FFMpegClass& Instance();

		void InitAv();
		void InitAvNetwork();
		void InitAvCodec();

		//TODO not used
		//void AddNewRtspStream(const char* uri);

		void SetRtspStream(const char* uri);

		void SetRenderApi(RenderAPI* render_api) { m_pRenderApi = render_api; };

		//void ReadFrames();
		void ReadFrame();

		inline bool hasInitAv() { return m_hasInitAv; }
		inline bool hasInitAvCodec() { return m_hasInitAvCodec; }
		inline bool hasInitAvNetwork() { return m_hasInitAvNetwork; }

		FFMpegStream* getStream() { return m_pStream; }
		RenderAPI* getRenderApi() { return m_pRenderApi; }

		inline void setTime(float time) { m_time = time; }
		inline float getTime() { return m_time; }

	private:

		static FFMpegClass m_instance;
		//TODO use many stream?
		//std::set<FFMpegStream> m_vStream;

		FFMpegStream* m_pStream = NULL;
		RenderAPI* m_pRenderApi = NULL;

		bool m_hasInitAvCodec;
		bool m_hasInitAv;
		bool m_hasInitAvNetwork;

		float m_time = 0;
	};
}

