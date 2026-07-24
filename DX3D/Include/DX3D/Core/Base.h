#pragma once

namespace dx3d {

	class Base {
	public:
		Base();
		virtual ~Base();

	protected:
		Base(const Base&) = delete; // delete copy constructor
		Base(Base&&) = delete; // delete move constructor
		Base& operator=(const Base&) = delete; // delete copy assignment operator
		Base& operator=(Base&&) = delete; // delete move assignment operator
	};

} // namespace dx3d
