#ifndef __ET_et_sigleton_H
#define __ET_et_sigleton_H

#include <memory>
#include <mutex>

template <typename T>
class et_sigleton {
public:
	static T *get_instance() {
		if (nullptr == instance_) {
			std::call_once(once_f_, [&]() { et_sigleton::instance_.reset(new T()); });
		}
		return instance_.get();
	}

private:
	et_sigleton();
	et_sigleton(const et_sigleton &rhs) = delete;
	et_sigleton &operator=(const et_sigleton &rhs) = delete;

private:
	static std::unique_ptr<T> instance_;
	static std::once_flag once_f_;
};

template <typename T>
std::unique_ptr<T> et_sigleton<T>::instance_ = nullptr;

template <typename T>
std::once_flag et_sigleton<T>::once_f_;

#endif // !__ET_et_sigleton_H
