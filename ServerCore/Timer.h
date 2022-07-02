#pragma once

namespace FrokEngine
{
	// �������� ����� Ÿ�̸Ӹ� ���� Ŭ�����Դϴ�.
	// FPS�� �� ������ �����մϴ�.
	class Timer
	{
	public:
		Timer();

		float TotalTime()const; // in seconds
		float DeltaTime()const; // in seconds
		float GetFPS() const;

		void Reset(); // Call before message loop.
		void Start(); // Call when unpaused.
		void Stop();  // Call when paused.
		void Tick();  // Call every frame.

	private:
		double _SecondsPerCount;
		double _DeltaTime;

		__int64 _BaseTime;
		__int64 _PausedTime;
		__int64 _StopTime;
		__int64 _PrevTime;
		__int64 _CurrTime;

		bool _Stopped;
	};
}