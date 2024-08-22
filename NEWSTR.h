#pragma once
#include <iostream>
#include <cassert>
#include <string>

class NEWSTR
{
public:
	NEWSTR();
	~NEWSTR();
	NEWSTR(const char ch);
	NEWSTR(const char ch, size_t count);
	NEWSTR(const char* ch);
	NEWSTR(std::string& string);
	NEWSTR(const NEWSTR& other);
	NEWSTR(NEWSTR&& other) noexcept;

	static size_t count();

	size_t size() const;
	size_t capacity() const;
	size_t length() const;
	size_t count_symbols(const char ch) const;
	size_t count_strings(const char* ch) const;
	size_t count_strings(const NEWSTR& newstr) const;
	size_t count_strings(const std::string& string) const;
	int find(const char ch) const;
	int find(const char* ch) const;
	int find(const NEWSTR& newstr) const;
	int find(const std::string& string) const;
	void resize(const size_t new_size);
	void resize(const size_t new_size, const char ch);
	void reserve(const size_t new_capacity);
	void shrink_to_fit();
	void push_front(const char ch);
	void append_front(const char* ch);
	void append_front(const NEWSTR& newstr);
	void append_front(const std::string& string);
	void push_back(const char ch);
	void append_back(const char* ch);
	void append_back(const NEWSTR& newstr);
	void append_back(const std::string& string);
	void clear();
	void remove(int index);
	void delete_symbols(const char ch);
	void delete_strings(const char* ch);
	void delete_strings(const NEWSTR& newstr);
	void delete_strings(const std::string& string);
	void pop_front();
	void pop_back();
	void erase(int index);
	void erase(int index, size_t count);
	void insert(int index, const char* ch);
	void insert(int index, const NEWSTR& newstr);
	void insert(int index, const std::string& string);
	void insert(int index, const char ch);
	void replace(int index, const char* ch);
	void replace(int index, const NEWSTR& newstr);
	void replace(int index, const std::string& string);
	void replace(int index, const char ch);
	void print() const;
	void toupper();
	void tolower();
	void reverse();
	void copy(NEWSTR* newstr);
	void swap(NEWSTR& newstr);
	void swap(std::string& string);
	bool empty() const;
	bool is_find(const char* ch) const;
	bool is_find(const NEWSTR& newstr) const;
	bool is_find(const std::string& string) const;
	bool is_find(const char ch) const;
	char& front();
	char& middle();
	char& back();
	char* c_nstr() const;
	char* begin();
	char* end();
	NEWSTR subnstr(int index, size_t length_) const;
	NEWSTR subnstr(int index) const;
	std::string substr(int index, size_t length_) const;
	std::string substr(int index) const;
	std::string nstr_to_str() const;

	bool operator==(const NEWSTR& right);
	bool operator!=(const NEWSTR& right);
	char& operator[](int index);
	NEWSTR& operator=(const NEWSTR& right);
	NEWSTR& operator+(const NEWSTR& right);
	NEWSTR& operator+(const char* right);
	friend NEWSTR operator+(const NEWSTR& left, const NEWSTR& right);
	friend NEWSTR operator+(const NEWSTR& left, const char* right);
	friend std::ostream& operator <<(std::ostream& streem, const NEWSTR& newstr);
	friend std::istream& operator >>(std::istream& streem, NEWSTR& newstr);

private:
	static int COUNT;
	char* _newstr;

	size_t _size = 0;
	size_t _capacity = 16;

	size_t _strlen(const char* ch) const;
	void _capacity_overexpression(size_t index_from);
	void checkOverflow();
};

