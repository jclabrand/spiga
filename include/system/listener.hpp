
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_listener_hpp__
#define __spiga_listener_hpp__

#include "configuration.h"

namespace spi {

template<typename PARAM1 = PVOID, typename PARAM2 = PVOID, typename PARAM3 = PVOID, typename PARAM4 = PVOID>
	class listener
{
public:
	inline listener() : __dlgt(new empty_delegate()) {}

	inline listener(void(*fnc)()) : __dlgt(new fnc_delegate0(fnc)) {}

	inline listener(void(*fnc)(PARAM1)) : __dlgt(new fnc_delegate1(fnc)) {}

	inline listener(void(*fnc)(PARAM1, PARAM2)) : __dlgt(new fnc_delegate2(fnc)) {}

	inline listener(void(*fnc)(PARAM1, PARAM2, PARAM3)) : __dlgt(new fnc_delegate3(fnc)) {}

	inline listener(void(*fnc)(PARAM1, PARAM2, PARAM3, PARAM4)) : __dlgt(new fnc_delegate4(fnc)) {}
	
	template<typename CLASS>
	inline listener(CLASS& obj, void (CLASS::*mvr)()) : __dlgt(new mvr_delegate0<CLASS>(obj, mvr)) {}

	template<typename CLASS>
	inline listener(CLASS& obj, void (CLASS::*mvr)(PARAM1)) : __dlgt(new mvr_delegate1<CLASS>(obj, mvr)) {}

	template<typename CLASS>
	inline listener(CLASS& obj, void (CLASS::*mvr)(PARAM1, PARAM2)) : __dlgt(new mvr_delegate2<CLASS>(obj, mvr)) {}

	template<typename CLASS>
	inline listener(CLASS& obj, void (CLASS::*mvr)(PARAM1, PARAM2, PARAM3)) : __dlgt(new mvr_delegate3<CLASS>(obj, mvr)) {}

	template<typename CLASS>
	inline listener(CLASS& obj, void (CLASS::*mvr)(PARAM1, PARAM2, PARAM3, PARAM4)) : __dlgt(new mvr_delegate4<CLASS>(obj, mvr)) {}

	inline listener(const listener& copy) : __dlgt(copy.__dlgt->clone()) {}

	inline virtual ~listener() { __dlgt->release(); }

	inline virtual bool operator == (const listener& ref) { return (*__dlgt == *ref.__dlgt); }

public:
	inline virtual void operator () () { (*__dlgt)(); }

	inline virtual void operator () (PARAM1 p1) { (*__dlgt)(p1); }

	inline virtual void operator () (PARAM1 p1, PARAM2 p2) { (*__dlgt)(p1, p2); }

	inline virtual void operator () (PARAM1 p1, PARAM2 p2, PARAM3 p3) { (*__dlgt)(p1, p2, p3); }

	inline virtual void operator () (PARAM1 p1, PARAM2 p2, PARAM3 p3, PARAM4 p4) { (*__dlgt)(p1, p2, p3, p4); }

protected:
	class idelegate
	{
	public:
		virtual void release() = 0;
		virtual idelegate* clone() = 0;

	public:
		virtual bool operator == (const idelegate& ref) = 0;

		virtual void operator () () {}
		virtual void operator () (PARAM1 p1) {}
		virtual void operator () (PARAM1 p1, PARAM2 p2) {}
		virtual void operator () (PARAM1 p1, PARAM2 p2, PARAM3 p3) {}
		virtual void operator () (PARAM1 p1, PARAM2 p2, PARAM3 p3, PARAM4 p4) {}
	};

	class empty_delegate : public idelegate
	{
	public:
		inline empty_delegate() {}

		inline virtual ~empty_delegate() {}

		inline void release() { empty_delegate* p = this; delete p; }

		inline idelegate* clone() { return new empty_delegate(); }

	public:
		inline bool operator == (const idelegate& ref) { return false; }
	};

	class fnc_delegate0 : public idelegate
	{
	public:
		typedef void(*DELEGATE)();

	public:
		inline fnc_delegate0(DELEGATE delegate) : __dlgt(delegate) {}

		virtual inline ~fnc_delegate0() {}

		virtual inline void release() { fnc_delegate0* p = this; delete p; }

		virtual inline idelegate* clone() { return new fnc_delegate0(__dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((fnc_delegate0*)&ref)->__dlgt; }

		inline void operator () () { (*__dlgt)(); }

	private:
		DELEGATE	__dlgt;
	};

	class fnc_delegate1 : public idelegate
	{
	public:
		typedef void(*DELEGATE)(PARAM1);

	public:
		inline fnc_delegate1(DELEGATE delegate) : __dlgt(delegate) {}

		virtual inline ~fnc_delegate1() {}

		virtual inline void release() { fnc_delegate1* p = this; delete p; }

		virtual inline idelegate* clone() { return new fnc_delegate1(__dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((fnc_delegate1*)&ref)->__dlgt; }

		inline void operator () (PARAM1 p1) { (*__dlgt)(p1); }

	private:
		DELEGATE	__dlgt;
	};

	class fnc_delegate2 : public idelegate
	{
	public:
		typedef void(*DELEGATE)(PARAM1, PARAM2);

	public:
		inline fnc_delegate2(DELEGATE delegate) : __dlgt(delegate) {}

		virtual inline ~fnc_delegate2() {}

		virtual inline void release() { fnc_delegate2* p = this; delete p; }

		virtual inline idelegate* clone() { return new fnc_delegate2(__dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((fnc_delegate2*)&ref)->__dlgt; }

		inline void operator () (PARAM1 p1, PARAM2 p2) { (*__dlgt)(p1, p2); }

	private:
		DELEGATE	__dlgt;
	};

	class fnc_delegate3 : public idelegate
	{
	public:
		typedef void(*DELEGATE)(PARAM1, PARAM2, PARAM3);

	public:
		inline fnc_delegate3(DELEGATE delegate) : __dlgt(delegate) {}

		virtual inline ~fnc_delegate3() {}

		virtual inline void release() { fnc_delegate3* p = this; delete p; }

		virtual inline idelegate* clone() { return new fnc_delegate3(__dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((fnc_delegate3*)&ref)->__dlgt; }

		inline void operator () (PARAM1 p1, PARAM2 p2, PARAM3 p3) { (*__dlgt)(p1, p2, p3); }

	private:
		DELEGATE	__dlgt;
	};

	class fnc_delegate4 : public idelegate
	{
	public:
		typedef void(*DELEGATE)(PARAM1, PARAM2, PARAM3, PARAM4);

	public:
		inline fnc_delegate4(DELEGATE delegate) : __dlgt(delegate) {}

		virtual inline ~fnc_delegate4() {}

		virtual inline void release() { fnc_delegate4* p = this; delete p; }

		virtual inline idelegate* clone() { return new fnc_delegate4(__dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((fnc_delegate4*)&ref)->__dlgt; }

		inline void operator () (PARAM1 p1, PARAM2 p2, PARAM3 p3, PARAM4 p4) { (*__dlgt)(p1, p2, p3, p4); }

	private:
		DELEGATE	__dlgt;
	};


	template<typename CLASS>
		class mvr_delegate0 : public idelegate
	{
	public:
		typedef void(CLASS::*DELEGATE)();

	public:
		inline mvr_delegate0(CLASS& obj, DELEGATE delegate) : __object(obj), __dlgt(delegate) {}

		virtual inline ~mvr_delegate0() {}

		virtual inline void release() { mvr_delegate0* p = this; delete p; }

		virtual inline idelegate* clone() { return new mvr_delegate0(__object, __dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((mvr_delegate0*)&ref)->__dlgt; }

		inline void operator () () { (__object.*__dlgt)(); }

	private:
		CLASS&		__object;
		DELEGATE	__dlgt;
	};

	template<typename CLASS>
		class mvr_delegate1 : public idelegate
	{
	public:
		typedef void (CLASS::*DELEGATE)(PARAM1);

	public:
		inline mvr_delegate1(CLASS& obj, DELEGATE delegate) : __object(obj), __dlgt(delegate) {}

		virtual inline ~mvr_delegate1() {}

		virtual inline void release() { mvr_delegate1* p = this; delete p; }

		virtual inline idelegate* clone() { return new mvr_delegate1(__object, __dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((mvr_delegate1*)&ref)->__dlgt; }

		inline void operator () (PARAM1 p1) { (__object.*__dlgt)(p1); }

	private:
		CLASS&		__object;
		DELEGATE	__dlgt;
	};

	template<typename CLASS>
		class mvr_delegate2 : public idelegate
	{
	public:
		typedef void (CLASS::*DELEGATE)(PARAM1, PARAM2);

	public:
		inline mvr_delegate2(CLASS& obj, DELEGATE delegate) : __object(obj), __dlgt(delegate) {}

		virtual inline ~mvr_delegate2() {}

		virtual inline void release() { mvr_delegate2* p = this; delete p; }

		virtual inline idelegate* clone() { return new mvr_delegate2(__object, __dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((mvr_delegate2*)&ref)->__dlgt; }

		inline void operator () (PARAM1 p1, PARAM2 p2) { (__object.*__dlgt)(p1, p2); }

	private:
		CLASS&		__object;
		DELEGATE	__dlgt;
	};

	template<typename CLASS>
		class mvr_delegate3 : public idelegate
	{
	public:
		typedef void (CLASS::*DELEGATE)(PARAM1, PARAM2, PARAM3);

	public:
		inline mvr_delegate3(CLASS& obj, DELEGATE delegate) : __object(obj), __dlgt(delegate) {}

		virtual inline ~mvr_delegate3() {}

		virtual inline void release() { mvr_delegate3* p = this; delete p; }

		virtual inline idelegate* clone() { return new mvr_delegate3(__object, __dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((mvr_delegate3*)&ref)->__dlgt; }

		inline void operator () (PARAM1 p1, PARAM2 p2, PARAM3 p3) { (__object.*__dlgt)(p1, p2, p3); }

	private:
		CLASS&		__object;
		DELEGATE	__dlgt;
	};

	template<typename CLASS>
		class mvr_delegate4 : public idelegate
	{
	public:
		typedef void (CLASS::*DELEGATE)(PARAM1, PARAM2, PARAM3, PARAM4);

	public:
		inline mvr_delegate4(CLASS& obj, DELEGATE delegate) : __object(obj), __dlgt(delegate) {}

		virtual inline ~mvr_delegate4() {}

		virtual inline void release() { mvr_delegate4* p = this; delete p; }

		virtual inline idelegate* clone() { return new mvr_delegate4(__object, __dlgt); }

	public:
		inline bool operator == (const idelegate& ref) { return __dlgt == ((mvr_delegate4*)&ref)->__dlgt; }

		inline void operator () (PARAM1 p1, PARAM2 p2, PARAM3 p3, PARAM4 p4) { (__object.*__dlgt)(p1, p2, p3, p4); }

	private:
		CLASS&		__object;
		DELEGATE	__dlgt;
	};

protected:
	idelegate* __dlgt;
};

} //end spi namespace

#endif //__spiga_listener_hpp__
