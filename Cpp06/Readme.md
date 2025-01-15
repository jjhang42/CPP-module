#CPP MOUDUEL 06
===============
This Subject is for four Cast Type of Cpp style.

I learn it.


## ex00
---------------

1. Cpp styles CastingType
* static_cast
	It's basic casting Form of Cpp.
	It's able to cast what 'upcasting'(From ChildClass To ParentsClass)

	It's usually using the nomal casting safely.

	ex: int -> double, char -> int

	If it's failed, The Compiler should return ERROR(Do not make programs).

	This cating is main casting form of ex00.

	It got me thinking that I had to be careful when using this casting with 'std::numeric_limits'

* dynamic_cast
	Dynamic_cast is using for downcasting safty. In CPP, uncasting can be implicitly, but downcasting can be dangerous, Programmers must use dynamic_cast operator for safty.

	** Using Pointer( safty down casting )
	1. Success
		return the Child Class
	2. Failure
		return the nullptr.

	** Using Reference
	1. Success
		return the Child Class
	2. Failure
		throw the exception what "std::bad_cast"

* const_cast

* reinterpret_cast
	It's Dangerous casting Type. this casting must be carefully.
	Because This can exchange pointer type to integer type, integer type to pointer type.

	if it's failed, The Program is able to do 'UB'.
> what is the 'inf'?
	'inf' is infinity. -inf means minus infinity of double, also -inff means minus infinity of float. +signs are also that.

> what is the 'non'?
	'non' means 'Not a Number'. float and double datatypes are able to return by undifine behaviar.

## ex01
* ex01 chose reinterpret_cast Type, because it was trying to cast a pointer to an integer. THis exersise is basic and easy.

## ex02
* ex02 chose dynamic_cast Type, because it can check their addresses, and return value of failures.

> what is the 'RTTI(RunTime Type Information)'
* RTTI is an abbreviation for RunTime Type Information. This mechanism that allows the type of an object to be determined during program execution. It's depanded RTTI Complete Object Locator. when clmpiling a class that contains a virtual function with RTTI Object.

This RTTI pointer is placed at the address just before the first address of the VF table.