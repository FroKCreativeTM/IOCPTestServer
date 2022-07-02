#include "pch.h"
#include "Timer.h"

// 타이머에 대한 초기화를 진행합니다.
namespace FrokEngine
{
	Timer::Timer()
		: _SecondsPerCount(0.0), _DeltaTime(-1.0), _BaseTime(0),
		_PausedTime(0), _PrevTime(0), _CurrTime(0), _Stopped(false)
	{
		__int64 countsPerSec;
		QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
		_SecondsPerCount = 1.0 / (double)countsPerSec;
	}

	// 실행시간 총합을 반환한다.
	float Timer::TotalTime() const
	{
		if (_Stopped)
			return (float)(((_StopTime - _PausedTime) - _BaseTime) * _SecondsPerCount);
		else
			return (float)(((_CurrTime - _PausedTime) - _BaseTime) * _SecondsPerCount);
	}

	float Timer::DeltaTime() const
	{
		// 각 프레임당 시간 즉 델타 타임을 반환합니다.
		return (float)_DeltaTime;
	}

	float Timer::GetFPS() const
	{
		return 1.0f / _DeltaTime;
	}

	void Timer::Reset()
	{
		__int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

		_BaseTime = currTime;
		_PrevTime = currTime;
		_StopTime = 0;
		_Stopped = false;
	}

	void Timer::Start()
	{
		__int64 startTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&startTime);

		if (_Stopped)
		{
			_PausedTime += (startTime - _StopTime);

			_PrevTime = startTime;
			_StopTime = 0;
			_Stopped = false;
		}
	}

	void Timer::Stop()
	{
		if (!_Stopped)
		{
			__int64 currTime;
			QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

			_StopTime = currTime;
			_Stopped = true;
		}
	}

	void Timer::Tick()
	{
		if (_Stopped)
		{
			_DeltaTime = 0.0;
			return;
		}

		__int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
		_CurrTime = currTime;

		_DeltaTime = (_CurrTime - _PrevTime) * _SecondsPerCount;

		_PrevTime = _CurrTime;

		if (_DeltaTime < 0.0)
		{
			_DeltaTime = 0.0;
		}
	}
}