#include "MagicalContainer.hpp"

using namespace ariel;

void MagicalContainer::addElement(int element) {
    sortElement(element);
    prime.clear();
    for(int a : ascend) if(isPrime(a)) prime.push_back(a);
    crossElement(element);
}

void MagicalContainer::removeElement(int element) {
    if(isPrime(element)) prime = _remove(prime, element);
    ascend = _remove(ascend, element);
    cross = _remove(cross, element);
}

bool MagicalContainer::isPrime(int n) const {
    if(n == 2) return true;
    if(n % 2 == 0 || n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++) if(n % i == 0) return false;
    return true;
}

void MagicalContainer::sortElement(int element) {
    if(ascend.empty()) ascend.push_back(element);
    else {
        bool inserted = false;
        vector<int> result;
        for(int a : ascend) {
            if(element < a && !inserted) {
                result.push_back(element);
                inserted = true;
            }
            result.push_back(a);
        }
        ascend = result;
        if(!inserted) ascend.push_back(element);
    }
}

void MagicalContainer::crossElement(int element) {
    if(cross.empty()) {
        cross.push_back(element);
        return;
    }
    cross.clear();
    vector<int> temp;
    for(int i = ascend.size() - 1; i >= 0; i--) temp.push_back(ascend[(unsigned long)i]);
    unsigned long i = 0;
    for(int a : ascend) {
        if (a == temp[i]) {
            cross.push_back(a);
            break;
        }
        if(a == temp[i - 1]) break;
        cross.push_back(a);
        cross.push_back(temp[i]);
        i++;
    }
}

vector<int> MagicalContainer::_remove(vector<int> elements, int element) {
    int i = 0;
    bool inElements = false;
    for(i = 0; i < elements.size(); i++) {
        if(elements[(unsigned long)i] == element) {
            inElements = true;
            break;
        }
    }
    if(!inElements) throw runtime_error("not in elements!");
    elements.erase(elements.begin() + i);
    return elements;
}

int MagicalContainer::size() const {
    return ascend.size();
}

vector<int> MagicalContainer::getAscend() const {
    return ascend;
}

vector<int> MagicalContainer::getPrime() const {
    return prime;
}

vector<int> MagicalContainer::getCross() const {
    return cross;
}

/*************************
*   Ascending iterator   * 
*************************/

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& _container) : container(&_container) {
    index = 0;
}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& _container, int _index) : container(&_container) {
    index = _index;
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(&other.getContainer()) {
    index = other.getIndex();
}

MagicalContainer& MagicalContainer::AscendingIterator::getContainer() const {
    return *container;
}

int MagicalContainer::AscendingIterator::getIndex() const {
    return index;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if(this->container != &other.getContainer()) throw runtime_error("not the same container");
    if(this != &other) {
        container = &other.getContainer();
        index = other.getIndex();
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return index == other.getIndex();
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return index > other.getIndex();
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return other > *this;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return container->getAscend()[(unsigned long) index];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if(index == container->getAscend().size()) throw runtime_error("maximum index!");
    index++;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    return AscendingIterator(*container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    return AscendingIterator(*container, container->getAscend().size());
}

/*************************
*   SideCross iterator   * 
*************************/

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& _container) : container(&_container) {
    index = 0;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& _container, int _index) : container(&_container) {
    index = _index;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : container(&other.getContainer()) {
    index = other.getIndex();
}

MagicalContainer& MagicalContainer::SideCrossIterator::getContainer() const {
    return *container;
}

int MagicalContainer::SideCrossIterator::getIndex() const {
    return index;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if(this->container != &other.getContainer()) throw runtime_error("not the same container");
    if(this != &other) {
        container = &other.getContainer();
        index = other.getIndex();
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return index == other.getIndex();
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return index > other.getIndex();
}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return other > *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return container->getCross()[(unsigned long) index];
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if(index == container->getCross().size()) throw runtime_error("maximum index!");
    index++;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return SideCrossIterator(*container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    return SideCrossIterator(*container, container->getCross().size());
}


/*************************
*     Prime iterator     * 
*************************/

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& _container) : container(&_container) {
    index = 0;
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& _container, int _index) : container(&_container) {
    index = _index;
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : container(&other.getContainer()){
    index = other.getIndex();
}

MagicalContainer& MagicalContainer::PrimeIterator::getContainer() const {
    return *container;
}

int MagicalContainer::PrimeIterator::getIndex() const {
    return index;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if(this->container != &other.getContainer()) throw runtime_error("not the same container");
    if(this != &other) {
        container = &other.getContainer();
        index = other.getIndex();
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return index == other.getIndex();
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return index > other.getIndex();
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return other > *this;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return container->getPrime()[(unsigned long) index];
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(index == container->getPrime().size()) throw runtime_error("maximum index!");
    index++;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    return PrimeIterator(*container);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    return PrimeIterator(*container, container->getPrime().size());
}