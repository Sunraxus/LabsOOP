#include <function/function.h>
#include <stdexcept> 

using namespace vehicles;
using namespace std;

void VehicleList::add(Vehicle v) {
	auto vehicles = new Vehicle * [_size + 1];
	for (int i = 0; i < _size; i++) {
		vehicles[i] = _array[i];
	}
	vehicles[_size] = new Vehicle(v);
	delete[] _array;
	_array = vehicles;
	_size++;
}

void VehicleList::clear() {
	if (_array == nullptr)
		return;
	for (int i = 0; i < _size; ++i)
		delete _array[i];
	_size = 0;
	delete[] _array;
	_array = nullptr;
}

VehicleList::VehicleList(const VehicleList& arr) {
	_size = arr._size;
	_array = new Vehicle * [_size];
	for (int i = 0; i < _size; i++) {
		_array[i] = new Vehicle;
		*_array[i] = arr[i];
	}
}

VehicleList::VehicleList(int size) {
	if (size < 0)throw std::invalid_argument("Size of array should be positive");
	_size = size;
	_array = new Vehicle * [size];
	for (int i = 0; i < size; i++) {
		_array[i] = new Vehicle;
		*_array[i] = Vehicle();
	}
}

int VehicleList::get_size() const {
	return _size;
}

Vehicle& VehicleList::operator[](int index) {
	if (index < 0 || _size <= index) {
		throw std::runtime_error("Index out of range.");
	}
	return *_array[index];
}

Vehicle VehicleList::operator[](int index) const {
	if (index < 0 || _size <= index) {
		throw std::runtime_error("Index out of range.");
	}
	return *_array[index];
}

void VehicleList::insert(int index, Vehicle& v) {
	if (index > _size || index < 0) throw std::runtime_error("Invalid index");

	Vehicle** ptr = new Vehicle * [_size + 1];
	for (int i = 0; i <= index; i++) {
		ptr[i] = new Vehicle;
	}
	memcpy(ptr, _array, sizeof(Vehicle*) * index);
	*ptr[index] = v;
	memcpy(ptr + index + 1, _array + index, sizeof(Vehicle*) * (_size - index));
	++_size;
	delete[] _array;
	_array = ptr;
	ptr = nullptr;
}

void VehicleList::remove(int index) {
	if (index < 0 || index >= _size)throw std::out_of_range("Invalid index.");
	Vehicle** ptr = new Vehicle * [_size - 1];
	for (int i = 0; i < _size - 1; i++) {
		ptr[i] = new Vehicle;
	}
	memcpy(ptr, _array, sizeof(Vehicle*) * index);
	memcpy(ptr + index, _array + index + 1, sizeof(Vehicle*) * (_size - index));
	delete _array[index];
	delete[] _array;
	_array = ptr;
	ptr = nullptr;
	--_size;
}

VehicleList::~VehicleList() {
	for (int i = 0; i < _size; i++) {
		delete _array[i];
	}
	delete[] _array;
}

void VehicleList::swap(VehicleList& arr) {
	std::swap(_size, arr._size);
	std::swap(_array, arr._array);
}

VehicleList& ::VehicleList::operator=(VehicleList arr) {
	this->swap(arr);
	return *this;
}


int vehicles::index_of_min_price(const VehicleList& vehicle, double m, double d) {
	int last_index = -1;
	int min_value = 0;
	const auto size = vehicle.get_size();
	for (int i = 0; i < size; ++i) {
		const auto value = vehicle[i].calc_price(m, d);
		if (last_index == -1 || value < min_value) {
			last_index = i;
			min_value = value;
		}
	}
	return last_index;
}

