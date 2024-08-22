#include "NEWSTR.h"

int NEWSTR::COUNT = 0;

NEWSTR::NEWSTR()
{
	_newstr = new char[_capacity];
	_newstr[_size] = '\0';
	COUNT++;
}

NEWSTR::~NEWSTR()
{
	delete[] _newstr;
	_newstr = nullptr;
	_size = 0;
	_capacity = 16;
	COUNT--;
}

NEWSTR::NEWSTR(const char ch)
{
	_newstr = new char[_capacity];
	_size = 1;
	_newstr[0] = ch;
	_newstr[1] = '\0';
	COUNT++;
}

NEWSTR::NEWSTR(const char ch, size_t count)
{
	_size = count;
	_newstr = new char[_capacity];
	checkOverflow();
	for (size_t i = 0; i < _size; i++) {
		_newstr[i] = ch;
	}
	_newstr[_size] = '\0';
	COUNT++;
}

NEWSTR::NEWSTR(const char* ch)
{
	_size = _strlen(ch);
	_newstr = new char[_capacity];
	checkOverflow();
	for (size_t i = 0; i < _size; i++) {
		_newstr[i] = ch[i];
	}
	_newstr[_size] = '\0';
	COUNT++;
}

NEWSTR::NEWSTR(std::string& string)
{
	_size = string.size();
	_capacity = string.capacity();
	checkOverflow();
	_newstr = new char[_capacity];
	for (size_t i = 0; i < _size; i++) {
		_newstr[i] = string[i];
	}
	_newstr[_size] = '\0';
	COUNT++;
}

NEWSTR::NEWSTR(const NEWSTR& other)
{
	_size = other._size;
	_capacity = other._capacity;
	_newstr = new char[_capacity];
	for (size_t i = 0; i < _size; i++) {
		_newstr[i] = other._newstr[i];
	}
	_newstr[_size] = '\0';
	COUNT++;
}

NEWSTR::NEWSTR(NEWSTR&& other) noexcept
{
	_size = other._size;
	_capacity = other._capacity;
	_newstr = new char[_capacity];
	for (size_t i = 0; i < _size; i++) {
		_newstr[i] = other._newstr[i];
	}
	_newstr[_size] = '\0';
	other._size = 0;
	other._capacity = 16;
	delete[] other._newstr;
	other._newstr = nullptr;
}

size_t NEWSTR::count()
{
	return COUNT;
}

size_t NEWSTR::capacity() const
{
	return _capacity;
}

size_t NEWSTR::length() const
{
	return _size;
}

size_t NEWSTR::count_symbols(const char ch) const
{
	size_t count = 0;
	for (size_t i = 0; i < _size; i++){
		if (_newstr[i] == ch) count++;
	}
	return count;
}

size_t NEWSTR::count_strings(const char* ch) const
{
	size_t count = 0;
	size_t size = _strlen(ch);
	for (size_t i = 0; i < _size; i++){
		if (_size - i < size) return count;
		else if (_newstr[i] == ch[0]) {
			int pointer = size - 1;
			size_t idx = 1;
			for (size_t j = i + 1; j < i + size; j++) {
				if (ch[idx] == _newstr[j]) {
					pointer--;
					idx++;
				}
				else break;
			}
			if (pointer == 0) count++;
			else continue;
		}
		else continue;
	}
	return count;
}

size_t NEWSTR::count_strings(const NEWSTR& newstr) const
{
	size_t count = 0;
	size_t size = newstr._size;
	for (size_t i = 0; i < _size; i++) {
		if (_size - i < size) return count;
		else if (_newstr[i] == newstr._newstr[0]) {
			int pointer = size - 1;
			size_t idx = 1;
			for (size_t j = i + 1; j < i + size; j++) {
				if (newstr._newstr[idx] == _newstr[j]) {
					pointer--;
					idx++;
				}
				else break;
			}
			if (pointer == 0) count++;
			else continue;
		}
		else continue;
	}
	return count;
}

size_t NEWSTR::count_strings(const std::string& string) const
{
	size_t count = 0;
	size_t size = string.size();
	for (size_t i = 0; i < _size; i++) {
		if (_size - i < size) return count;
		else if (_newstr[i] == string[0]) {
			int pointer = size - 1;
			size_t idx = 1;
			for (size_t j = i + 1; j < i + size; j++) {
				if (string[idx] == _newstr[j]) {
					pointer--;
					idx++;
				}
				else break;
			}
			if (pointer == 0) count++;
			else continue;
		}
		else continue;
	}
	return count;
}

int NEWSTR::find(const char ch) const
{
	for (int i = 0; i < _size; i++){
		if (_newstr[i] == ch) return i;
	}
	return -1;
}

int NEWSTR::find(const char* ch) const
{
	int pos = -1;
	size_t size = _strlen(ch);
	for (size_t i = 0; i < _size; i++) {
		if (_size - i < size) return -1;
		else if (_newstr[i] == ch[0]) {
			pos = i;
			int pointer = size - 1;
			size_t idx = 1;
			for (size_t j = i + 1; j < i + size; j++) {
				if (ch[idx] == _newstr[j]) {
					pointer--;
					idx++;
				}
				else break;
			}
			if (pointer == 0) return pos;
			else continue;
		}
		else continue;
	}
	return -1;
}

int NEWSTR::find(const NEWSTR& newstr) const
{
	int pos = -1;
	size_t size = newstr._size;
	for (size_t i = 0; i < _size; i++) {
		if (_size - i < size) return -1;
		else if (_newstr[i] == newstr._newstr[0]) {
			pos = i;
			int pointer = size - 1;
			size_t idx = 1;
			for (size_t j = i + 1; j < i + size; j++) {
				if (newstr._newstr[idx] == _newstr[j]) {
					pointer--;
					idx++;
				}
				else break;
			}
			if (pointer == 0) return pos;
			else continue;
		}
		else continue;
	}
	return -1;
}

int NEWSTR::find(const std::string& string) const
{
	int pos = -1;
	size_t size = string.size();
	for (size_t i = 0; i < _size; i++) {
		if (_size - i < size) return -1;
		else if (_newstr[i] == string[0]) {
			pos = i;
			int pointer = size - 1;
			size_t idx = 1;
			for (size_t j = i + 1; j < i + size; j++) {
				if (string[idx] == _newstr[j]) {
					pointer--;
					idx++;
				}
				else break;
			}
			if (pointer == 0) return pos;
			else continue;
		}
		else continue;
	}
	return -1;
}

void NEWSTR::resize(const size_t new_size)
{
	assert(_size <= new_size);
	while (_size < new_size) {
		push_back(' ');
	}
}

void NEWSTR::resize(const size_t new_size, const char ch)
{
	assert(_size <= new_size);
	while (_size < new_size) {
		push_back(ch);
	}
}

void NEWSTR::reserve(const size_t new_capacity)
{
	assert(_capacity <= new_capacity);
	_capacity = new_capacity;
	_capacity_overexpression(0);
}

void NEWSTR::shrink_to_fit()
{
	if (_capacity != _size + 1) {
		_capacity = _size + 1;
		_capacity_overexpression(0);
	}
}

void NEWSTR::push_front(const char ch)
{
	if (_size >= _capacity - 1) {
		_capacity = _size + 16;
		_capacity_overexpression(0);
	}
	char* buff = new char[_capacity];
	buff[0] = ch;
	_size++;
	for (size_t i = 1; i < _size; i++){
		buff[i] = _newstr[i - 1];
	}
	delete[] _newstr;
	_newstr = new char[_capacity];
	for (size_t i = 0; i < _size; i++) {
		_newstr[i] = buff[i];
	}
	_newstr[_size] = '\0';
	delete[] buff;
	buff = nullptr;
}

void NEWSTR::append_front(const char* ch)
{
	size_t len = _strlen(ch);
	if (_capacity - _size < len) {
		_capacity = _size + len + 16;
		_capacity_overexpression(0);
	}
	for (size_t i = 0; i < len; i++) {
		push_front(ch[len - i - 1]);
	}
}

void NEWSTR::append_front(const NEWSTR& newstr)
{
	size_t len = newstr._size;
	if (_capacity - _size < len) {
		_capacity = _size + len + 16;
		_capacity_overexpression(0);
	}
	for (size_t i = 0; i < len; i++) {
		push_front(newstr._newstr[len - i - 1]);
	}
}

void NEWSTR::append_front(const std::string& string)
{
	size_t len = string.size();
	if (_capacity - _size < len) {
		_capacity = _size + len + 16;
		_capacity_overexpression(0);
	}
	for (size_t i = 0; i < len; i++) {
		push_front(string[len - i - 1]);
	}
}

void NEWSTR::push_back(const char ch)
{
	if (_size >= _capacity - 1) {
		_capacity = _size + 16;
		_capacity_overexpression(0);
	}
	_newstr[_size] = ch;
	_size++;
	_newstr[_size] = '\0';
}

void NEWSTR::append_back(const char* ch)
{
	size_t len = _strlen(ch);
	if (_capacity - _size < len) {
		_capacity = _size + len + 16;
		_capacity_overexpression(0);
	}
	for (size_t i = 0; i < len; i++) {
		push_back(ch[i]);
	}
}

void NEWSTR::append_back(const NEWSTR& newstr)
{
	size_t len = newstr._size;
	if (_capacity - _size < len) {
		_capacity = _size + len + 16;
		_capacity_overexpression(0);
	}
	for (size_t i = 0; i < len; i++) {
		push_back(newstr._newstr[i]);
	}
}

void NEWSTR::append_back(const std::string& string)
{
	size_t len = string.size();
	if (_capacity - _size < len) {
		_capacity = _size + len + 16;
		_capacity_overexpression(0);
	}
	for (size_t i = 0; i < len; i++) {
		push_back(string[i]);
	}
}

void NEWSTR::clear()
{
	if (!empty()) {
		_size = 0;
		_capacity_overexpression(0);
	}
}

void NEWSTR::remove(int index)
{
	erase(index, 1);
}

void NEWSTR::delete_symbols(const char ch)
{
	for (size_t i = 0; i < _size; i++){
		if (_newstr[i] == ch) { erase(i, 1); i--; }
	}
}

void NEWSTR::delete_strings(const char* ch)
{
	size_t size = _strlen(ch);
	int pos = find(ch);
	while (pos != -1) {
		erase(pos, size);
		pos = find(ch);
	}
}

void NEWSTR::delete_strings(const NEWSTR& newstr)
{
	size_t size = newstr._size;
	int pos = find(newstr);
	while (pos != -1) {
		erase(pos, size);
		pos = find(newstr);
	}
}

void NEWSTR::delete_strings(const std::string& string)
{
	size_t size = string.size();
	int pos = find(string);
	while (pos != -1) {
		erase(pos, size);
		pos = find(string);
	}
}

void NEWSTR::pop_front()
{
	assert(_size > 0);
	_capacity_overexpression(1);
	_size--;
	_newstr[_size] = '\0';
}

void NEWSTR::pop_back()
{
	assert(_size > 0);
	_size--;
	_capacity_overexpression(0);
}

void NEWSTR::erase(int index)
{
	int size = _size;
	if (index >= 0) {
		assert(index < _size);
		for (index; index < size; index++) {
			pop_back();
		}
	}
	else {
		assert(abs(index) <= _size);
		int idx = _size + index;
		for (idx; idx >= 0; idx--) {
			pop_front();
		}
	}
}

void NEWSTR::erase(int index, size_t count)
{
	if (index >= 0) {
		int length_ = index + count;
		assert(index < _size);
		assert(length_ <= _size);
		char* buff = new char[_capacity];
		for (int i = 0; i < index; i++) {
			buff[i] = _newstr[i];
		}
		for (int i = length_; i < _size; i++) {
			buff[i - count] = _newstr[i];
		}
		_size -= count;
		delete[] _newstr;
		_newstr = new char[_capacity];
		for (size_t i = 0; i < _size; i++){
			_newstr[i] = buff[i];
		}
		_newstr[_size] = '\0';
		delete[] buff;
		buff = nullptr;
	}
	else {
		index += _size;
		int length_ = index - count;
		assert(index < _size);
		assert(length_ + 1 <= _size);
		char* buff = new char[_capacity];
		for (int i = _size - 1; i > index; i--) {
			buff[i - count] = _newstr[i];
		}
		for (int i = length_; i >= 0; i--) {
			buff[i] = _newstr[i];
		}
		_size -= count;
		delete[] _newstr;
		_newstr = new char[_capacity];
		for (size_t i = 0; i < _size; i++) {
			_newstr[i] = buff[i];
		}
		_newstr[_size] = '\0';
		delete[] buff;
		buff = nullptr;
	}
}

void NEWSTR::insert(int index, const char* ch)
{
	if (index >= 0) {
		assert(index <= _size);
	}
	else {
		assert(abs(index) <= _size + 1);
		index += _size + 1;
	}
	size_t size = _strlen(ch);
	char* buff = new char[size];
	int idx = 0;
	for (int i = index; i < _size; i++) {
		buff[idx] = _newstr[i];
		idx++;
	}
	idx = 0;
	_size += size;
	checkOverflow();
	for (int i = index; i < index + size; i++) {
		_newstr[i] = ch[idx];
		idx++;
	}
	idx = 0;
	for (int i = index + size; i < _size; i++){
		_newstr[i] = buff[idx];
		idx++;
	}
	_newstr[_size] = '\0';
	buff = nullptr;
}

void NEWSTR::insert(int index, const NEWSTR& newstr)
{
	if (index >= 0) {
		assert(index <= _size);
	}
	else {
		assert(abs(index) <= _size + 1);
		index += _size + 1;
	}
	size_t size = newstr._size;
	char* buff = new char[size];
	int idx = 0;
	for (int i = index; i < _size; i++) {
		buff[idx] = _newstr[i];
		idx++;
	}
	idx = 0;
	_size += size;
	checkOverflow();
	for (int i = index; i < index + size; i++) {
		_newstr[i] = newstr._newstr[idx];
		idx++;
	}
	idx = 0;
	for (int i = index + size; i < _size; i++) {
		_newstr[i] = buff[idx];
		idx++;
	}
	_newstr[_size] = '\0';
	buff = nullptr;
}

void NEWSTR::insert(int index, const std::string& string)
{
	if (index >= 0) {
		assert(index <= _size);
	}
	else {
		assert(abs(index) <= _size + 1);
		index += _size + 1;
	}
	size_t size = string.size();
	char* buff = new char[size];
	int idx = 0;
	for (int i = index; i < _size; i++) {
		buff[idx] = _newstr[i];
		idx++;
	}
	idx = 0;
	_size += size;
	checkOverflow();
	for (int i = index; i < index + size; i++) {
		_newstr[i] = string[idx];
		idx++;
	}
	idx = 0;
	for (int i = index + size; i < _size; i++) {
		_newstr[i] = buff[idx];
		idx++;
	}
	_newstr[_size] = '\0';
	buff = nullptr;
}

void NEWSTR::insert(int index, const char ch)
{
	if (index >= 0) {
		assert(index <= _size);
	}
	else {
		assert(abs(index) <= _size + 1);
		index += _size + 1;
	}
	char* buff = new char[_size + 1];
	int idx = 0;
	for (int i = index; i < _size; i++) {
		buff[idx] = _newstr[i];
		idx++;
	}
	idx = 0;
	_size++;
	checkOverflow();
	_newstr[index] = ch;
	idx = 0;
	for (int i = index + 1; i < _size; i++) {
		_newstr[i] = buff[idx];
		idx++;
	}
	_newstr[_size] = '\0';
	buff = nullptr;
}

void NEWSTR::replace(int index, const char* ch)
{
	size_t size = _strlen(ch);
	int idx = 0;
	if (index >= 0) {
		assert(index < _size);
		assert(index + size <= _size);
		for (size_t i = index; i < index + size; i++) {
			_newstr[i] = ch[idx];
			idx++;
		}
	}
	else {
		assert(abs(index) <= _size);
		index += _size;
		assert(index - (int)size + 1 >= 0);
		for (size_t i = index - size + 1; i < index + 1; i++) {
			_newstr[i] = ch[idx];
			idx++;
		}
	}
}

void NEWSTR::replace(int index, const NEWSTR& newstr)
{
	size_t size = newstr._size;
	int idx = 0;
	if (index >= 0) {
		assert(index < _size);
		assert(index + size <= _size);
		for (size_t i = index; i < index + size; i++) {
			_newstr[i] = newstr._newstr[idx];
			idx++;
		}
	}
	else {
		assert(abs(index) <= _size);
		index += _size;
		assert(index - (int)size + 1 >= 0);
		for (size_t i = index - size + 1; i < index + 1; i++) {
			_newstr[i] = newstr._newstr[idx];
			idx++;
		}
	}
}

void NEWSTR::replace(int index, const std::string& string)
{
	size_t size = string.size();
	int idx = 0;
	if (index >= 0) {
		assert(index < _size);
		assert(index + size <= _size);
		for (size_t i = index; i < index + size; i++) {
			_newstr[i] = string[idx];
			idx++;
		}
	}
	else {
		assert(abs(index) <= _size);
		index += _size;
		assert(index - (int)size + 1 >= 0);
		for (size_t i = index - size + 1; i < index + 1; i++) {
			_newstr[i] = string[idx];
			idx++;
		}
	}
}

void NEWSTR::replace(int index, const char ch)
{
	if (index >= 0) {
		assert(index < _size);
	}
	else {
		assert(abs(index) <= _size);
		index += _size;
	}
	_newstr[index] = ch;
}

void NEWSTR::print() const
{
	std::cout << *this << '\n';
}

void NEWSTR::toupper()
{
	for (size_t i = 0; i < _size; i++) {
		int symb = (int)_newstr[i];
		if ((symb >= 97 && symb <= 122)
			|| (symb >= -32 && symb <= -1)) {
			symb -= 32;
			_newstr[i] = (char)symb;
		}
	}
}

void NEWSTR::tolower()
{
	for (size_t i = 0; i < _size; i++){
		int symb = (int)_newstr[i];
		if ((symb >= 65 && symb <= 90)
			|| (symb >= -64 && symb <= -33)) {
			symb += 32;
			_newstr[i] = (char)symb;
		}
	}
}

void NEWSTR::reverse()
{
	char* buff = new char[_capacity];
	for (size_t i = 0; i < _size; i++){
		buff[i] = _newstr[i];
	}
	for (size_t i = 0; i < _size; i++){
		_newstr[i] = buff[_size - i - 1];
	}
	delete[] buff;
	buff = nullptr;
}

void NEWSTR::copy(NEWSTR* newstr)
{
	newstr->_size = _size;
	newstr->_capacity = _capacity;
	delete[] newstr->_newstr;
	newstr->_newstr = new char[newstr->_capacity];
	for (size_t i = 0; i < newstr->_size; i++) {
		newstr->_newstr[i] = _newstr[i];
	}
	newstr->_newstr[newstr->_size] = '\0';
}

void NEWSTR::swap(NEWSTR& newstr)
{
	size_t buff_size = newstr._size;
	size_t buff_capacity = newstr._capacity;
	char* buff = new char[buff_capacity];
	for (size_t i = 0; i < buff_size; i++){
		buff[i] = newstr[i];
	}
	copy(&newstr);
	delete[] _newstr;
	_size = buff_size;
	_capacity = buff_capacity;
	_newstr = new char[_capacity];
	for (size_t i = 0; i < buff_size; i++) {
		_newstr[i] = buff[i];
	}
	_newstr[_size] = '\0';
	delete[] buff;
	buff = nullptr;
}

void NEWSTR::swap(std::string& string)
{
	size_t buff_size = string.size();
	size_t buff_capacity = string.capacity();
	char* buff = new char[buff_capacity];
	for (size_t i = 0; i < buff_size; i++) {
		buff[i] = string[i];
	}
	string = nstr_to_str();
	delete[] _newstr;
	_size = buff_size;
	_capacity = buff_capacity;
	_newstr = new char[_capacity];
	for (size_t i = 0; i < buff_size; i++) {
		_newstr[i] = buff[i];
	}
	_newstr[_size] = '\0';
	delete[] buff;
	buff = nullptr;
}

bool NEWSTR::empty() const
{
	return (_size == 0);
}

bool NEWSTR::is_find(const char* ch) const
{
	size_t size = _strlen(ch);
	for (size_t i = 0; i < _size; i++) {
		if (_size - i < size) return false;
		else if (_newstr[i] == ch[0]) {
			int pointer = size - 1;
			size_t idx = 1;
			for (size_t j = i + 1; j < i + size; j++) {
				if (ch[idx] == _newstr[j]) {
					pointer--;
					idx++;
				}
				else break;
			}
			if (pointer == 0) return true;
			else continue;
		}
		else continue;
	}
	return false;
}

bool NEWSTR::is_find(const NEWSTR& newstr) const
{
	size_t size = newstr._size;
	for (size_t i = 0; i < _size; i++) {
		if (_size - i < size) return false;
		else if (_newstr[i] == newstr._newstr[0]) {
			int pointer = size - 1;
			size_t idx = 1;
			for (size_t j = i + 1; j < i + size; j++) {
				if (newstr._newstr[idx] == _newstr[j]) {
					pointer--;
					idx++;
				}
				else break;
			}
			if (pointer == 0) return true;
			else continue;
		}
		else continue;
	}
	return false;
}

bool NEWSTR::is_find(const std::string& string) const
{
	size_t size = string.size();
	for (size_t i = 0; i < _size; i++) {
		if (_size - i < size) return false;
		else if (_newstr[i] == string[0]) {
			int pointer = size - 1;
			size_t idx = 1;
			for (size_t j = i + 1; j < i + size; j++) {
				if (string[idx] == _newstr[j]) {
					pointer--;
					idx++;
				}
				else break;
			}
			if (pointer == 0) return true;
			else continue;
		}
		else continue;
	}
	return false;
}

bool NEWSTR::is_find(const char ch) const
{
	for (size_t i = 0; i < _size; i++){
		if (_newstr[i] == ch) return true;
	}
	return false;
}

char& NEWSTR::front()
{
	return _newstr[0];
}

char& NEWSTR::middle()
{
	if (_size % 2 == 0) return _newstr[_size / 2 - 1];
	else return _newstr[_size / 2];
}

char& NEWSTR::back()
{
	if (!empty()) {
		return _newstr[_size - 1];
	}
	else return _newstr[0];
}

char* NEWSTR::c_nstr() const
{
	return _newstr;
}

char* NEWSTR::begin()
{
	return _newstr;
}

char* NEWSTR::end()
{
	return begin() + _size;
}

NEWSTR NEWSTR::subnstr(int index, size_t length_) const
{
	NEWSTR newstr;
	if (index >= 0) {
		assert(index < _size);
	}
	else {
		assert(abs(index) <= _size);
		index += _size;
	}
	assert(index + length_ <= _size);
	newstr._size = length_;
	newstr.checkOverflow();
	int idx = 0;
	for (int i = index; i < index + length_; i++){
		newstr[idx] = _newstr[i];
		idx++;
	}
	newstr._newstr[newstr._size] = '\0';
 	return newstr;
}

NEWSTR NEWSTR::subnstr(int index) const
{
	NEWSTR newstr;
	if (index >= 0) {
		assert(index < _size);
	}
	else {
		assert(abs(index) <= _size);
		index += _size;
	}
	newstr._size = _size - index;
	newstr.checkOverflow();
	int idx = 0;
	for (int i = index; i < _size; i++) {
		newstr[idx] = _newstr[i];
		idx++;
	}
	newstr._newstr[newstr._size] = '\0';
	return newstr;
}

std::string NEWSTR::substr(int index, size_t length_) const
{
	std::string str;
	if (index >= 0) {
		assert(index < _size);
	}
	else {
		assert(abs(index) <= _size);
		index += _size;
	}
	assert(index + length_ <= _size);
	str.resize(length_);
	int idx = 0;
	for (int i = index; i < index + length_; i++) {
		str[idx] = _newstr[i];
		idx++;
	}
	return str;
}

std::string NEWSTR::substr(int index) const
{
	std::string str;
	if (index >= 0) {
		assert(index < _size);
	}
	else {
		assert(abs(index) <= _size);
		index += _size;
	}
	str.resize(_size - index);
	int idx = 0;
	for (int i = index; i < _size; i++) {
		str[idx] = _newstr[i];
		idx++;
	}
	return str;
}

std::string NEWSTR::nstr_to_str() const
{
	std::string str;
	str.reserve(_capacity);
	str.resize(_size);
	for (size_t i = 0; i < _size; i++){
		str[i] = _newstr[i];
	}
	return str;
}

bool NEWSTR::operator==(const NEWSTR& right)
{
	if (_capacity == right._capacity && _size == right._size) {
		size_t pointer = _size;
		for (size_t i = 0; i < _size; i++){
			if ((*this)[i] == right._newstr[i]) pointer--;
		}
		if (pointer == 0) return true;
	}
	return false;
}

bool NEWSTR::operator!=(const NEWSTR & right)
{
	if (_capacity == right._capacity && _size == right._size) {
		size_t pointer = _size;
		for (size_t i = 0; i < _size; i++) {
			if ((*this)[i] == right._newstr[i]) pointer--;
		}
		if (pointer == 0) return false;
	}
	return true;
}

char& NEWSTR::operator[](int index)
{
	if (index >= 0) {
		assert(index < _size);
		return _newstr[index];
	}
	else {
		assert(abs(index) <= _size);
		return _newstr[_size + index];
	}
}

NEWSTR& NEWSTR::operator=(const NEWSTR& right)
{
	if (this == &right) {
		return *this;
	}
	_size = right._size;
	_capacity = right._capacity;
	delete[] _newstr;
	_newstr = new char[right._capacity];
	for (size_t i = 0; i < _size; i++){
		_newstr[i] = right._newstr[i];
	}
	_newstr[_size] = '\0';
	return *this;
}

NEWSTR& NEWSTR::operator+(const NEWSTR& right)
{
	size_t temp_size = _size;
	_size += right._size;
	checkOverflow();
	for (size_t i = temp_size; i < _size; i++){
		_newstr[i] = right._newstr[i - temp_size];
	}
	_newstr[_size] = '\0';
	return *this;
}

NEWSTR& NEWSTR::operator+(const char* right)
{
	size_t temp_size = _size;
	_size += _strlen(right);
	checkOverflow();
	for (size_t i = temp_size; i < _size; i++) {
		_newstr[i] = right[i - temp_size];
	}
	_newstr[_size] = '\0';
	return *this;
}

size_t NEWSTR::size() const
{
	return _size;
}

size_t NEWSTR::_strlen(const char* ch) const
{
	size_t size = 0;
	while (ch[size] != '\0') size++;
	return size;
}

void NEWSTR::_capacity_overexpression(size_t index_from)
{
	char* buff = new char[_capacity];
	int idx = 0;
	for (index_from; index_from < _size; index_from++) {
		buff[idx] = _newstr[index_from];
		idx++;
	}
	delete[] _newstr;
	_newstr = new char[_capacity];
	for (size_t i = 0; i < _size; i++){
		_newstr[i] = buff[i];
	}
	_newstr[_size] = '\0';
	delete[] buff;
	buff = nullptr;
}

void NEWSTR::checkOverflow()
{
	if (_size > _capacity - 1) {
		_capacity = _size + 16;
		_capacity_overexpression(0);
	}
}

NEWSTR operator+(const NEWSTR& left, const NEWSTR& right)
{
	NEWSTR res;
	res._size = left._size + right._size;
	res._capacity = res._size + 16;
	delete[] res._newstr;
	res._newstr = new char[res._capacity];
	for (size_t i = 0; i < left._size; i++) {
		res._newstr[i] = left._newstr[i];
	}
	size_t idx = 0;
	for (size_t i = left._size; i < res._size; i++){
		res._newstr[i] = right._newstr[idx];
		idx++;
	}
	res._newstr[res._size] = '\0';
	return res;
}

NEWSTR operator+(const NEWSTR& left, const char* right)
{
	NEWSTR res;
	res._size = left._size + left._strlen(right);
	res._capacity = res._size + 16;
	delete[] res._newstr;
	res._newstr = new char[res._capacity];
	for (size_t i = 0; i < left._size; i++) {
		res._newstr[i] = left._newstr[i];
	}
	size_t idx = 0;
	for (size_t i = left._size; i < res._size; i++) {
		res._newstr[i] = right[idx];
		idx++;
	}
	res._newstr[res._size] = '\0';
	return res;
}

std::ostream& operator<<(std::ostream& streem, const NEWSTR& newstr)
{
	for (int i = 0; i < newstr._size; i++){
		streem << newstr._newstr[i];
	}
	return streem;
}

std::istream& operator>>(std::istream& streem, NEWSTR& newstr)
{
	// не смог по-другому реализовать из-за недостатка знаний -_-
	// сорян за говнокод
	std::string str;
	streem >> str;
	for (size_t i = 0; i < str.size(); i++){
		newstr.push_back(str[i]);
	}
	return streem;
}
