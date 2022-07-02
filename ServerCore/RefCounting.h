#pragma once

namespace FrokEngine
{
	/*---------------
	   RefCountable
	----------------*/
	
	// 레퍼런스 카운트를 관리하는 클래스입니다.
	// shared_ptr를 구현하기 위해 사용하는 클래스입니다.
	// 1부터 시작하며 0이 되면 그 메모리를 해제하도록 만듭니다.

	
	class RefCountable
	{
	public:
		RefCountable() : _refCount(1) { }
		virtual ~RefCountable() { }

		int32 GetRefCount() { return _refCount; }

		int32 AddRef() { return ++_refCount; }
		int32 ReleaseRef()
		{
			int32 refCount = --_refCount;
			if (refCount == 0)
			{
				delete this;
			}
			return refCount;
		}

	protected:
		atomic<int32> _refCount;
	};

	/*---------------
	   SharedPtr
	----------------*/

	// weak_ptr은 shared_ptr을 받아내지만
	// shared_ptr처럼 사용을 할 수 없다.
	// 먼저 expired를 이용해서 참조하고 있는 포인터가 있는지 확인하고
	// 그 이후에 이용하는 방식이다.
	template<typename T>
	class TSharedPtr
	{
	public:
		TSharedPtr() { }
		TSharedPtr(T* ptr) { Set(ptr); }

		// 복사
		TSharedPtr(const TSharedPtr& rhs) { Set(rhs._ptr); }
		// 이동
		TSharedPtr(TSharedPtr&& rhs) { _ptr = rhs._ptr; rhs._ptr = nullptr; }
		// 상속 관계 복사
		template<typename U>
		TSharedPtr(const TSharedPtr<U>& rhs) { Set(static_cast<T*>(rhs._ptr)); }

		~TSharedPtr() { Release(); }

	public:
		// 복사 연산자
		TSharedPtr& operator=(const TSharedPtr& rhs)
		{
			if (_ptr != rhs._ptr)
			{
				Release();
				Set(rhs._ptr);
			}
			return *this;
		}

		// 이동 연산자
		TSharedPtr& operator=(TSharedPtr&& rhs)
		{
			Release();
			_ptr = rhs._ptr;
			rhs._ptr = nullptr;
			return *this;
		}

		bool		operator==(const TSharedPtr& rhs) const { return _ptr == rhs._ptr; }
		bool		operator==(T* ptr) const { return _ptr == ptr; }
		bool		operator!=(const TSharedPtr& rhs) const { return _ptr != rhs._ptr; }
		bool		operator!=(T* ptr) const { return _ptr != ptr; }
		bool		operator<(const TSharedPtr& rhs) const { return _ptr < rhs._ptr; }
		T* operator*() { return _ptr; }
		const T* operator*() const { return _ptr; }
		operator T* () const { return _ptr; }
		T* operator->() { return _ptr; }
		const T* operator->() const { return _ptr; }

		bool IsNull() { return _ptr == nullptr; }

	private:
		inline void Set(T* ptr)
		{
			_ptr = ptr;
			if (ptr)
				ptr->AddRef();
		}

		inline void Release()
		{
			if (_ptr != nullptr)
			{
				_ptr->ReleaseRef();
				_ptr = nullptr;
			}
		}

	private:
		T* _ptr = nullptr;
	};
}