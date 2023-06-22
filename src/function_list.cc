#include <function/function.h>
#include <stdexcept> 

using namespace vehicles;
using namespace std;

VehicleList::VehicleList() : _size(0) {}

int VehicleList::get_size() const {
	return _size;
}

Vehicle VehicleList::operator[](int index) const {
	if (index < 0 || _size <= index) {
		throw runtime_error("Index out of range.");
	}

	return _vehicles[index];
}

void VehicleList::insert(int index, Vehicle v) {
    if (_size == CAPACITY) {
        throw runtime_error("Full capacity reached.");
    }
    for (int i = _size - 1; i >= index; i--) {
        _vehicles[i + 1] = _vehicles[i];
    }
    _vehicles[index] = v;
    ++_size;
}

void VehicleList::remove(int index) {
    if (index < 0 || index >= _size) {
        throw out_of_range("Invalid index.");
    }
    for (int i = index; i < _size - 1; i++) {
        _vehicles[i] = _vehicles[i + 1];
    }
    --_size;
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

