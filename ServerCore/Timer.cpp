#include "pch.h"
#include "Timer.h"

// Ÿ�̸ӿ� ���� �ʱ�ȭ�� �����մϴ�.
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

	// ����ð� ������ ��ȯ�Ѵ�.
	float Timer::TotalTime() const
	{
		if (_Stopped)
			return (float)(((_StopTime - _PausedTime) - _BaseTime) * _SecondsPerCount);
		else
			return (float)(((_CurrTime - _PausedTime) - _BaseTime) * _SecondsPerCount);
	}

	float Timer::DeltaTime() const
	{
		// �� �����Ӵ� �ð� �� ��Ÿ Ÿ���� ��ȯ�մϴ�.
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