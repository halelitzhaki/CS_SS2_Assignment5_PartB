#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

namespace ariel{
    class MagicalContainer {
        private:
            vector<int> prime, ascend, cross;

            bool isPrime(int) const;
            void sortElement(int);
            void crossElement(int);
            vector<int> _remove(vector<int>, int);
        
        public:
            MagicalContainer() = default;
            MagicalContainer(const MagicalContainer&) = default;
            MagicalContainer(MagicalContainer&&) = default;
            MagicalContainer& operator=(const MagicalContainer&) = default;
            MagicalContainer& operator=(MagicalContainer&&) = default;
            ~MagicalContainer() = default;

            void addElement(int);
            void removeElement(int);
            
            vector<int> getAscend() const;
            vector<int> getPrime() const;
            vector<int> getCross() const;

            int size() const;

            class AscendingIterator {
                private:
                    MagicalContainer * container;
                    int index;

                public:
                    AscendingIterator() : container(nullptr), index(0) {};
                    AscendingIterator(MagicalContainer&);
                    AscendingIterator(MagicalContainer&, int);
                    AscendingIterator(const AscendingIterator&);
                    AscendingIterator(AscendingIterator&&) = default;
                    AscendingIterator& operator=(AscendingIterator&&) = default;
                    ~AscendingIterator() { };

                    AscendingIterator& operator=(const AscendingIterator&);
                    bool operator==(const AscendingIterator&) const;
                    bool operator!=(const AscendingIterator&) const;
                    bool operator>(const AscendingIterator&) const;
                    bool operator<(const AscendingIterator&) const;
                    int operator*() const;
                    AscendingIterator& operator++();

                    AscendingIterator begin() const;
                    AscendingIterator end() const;

                    MagicalContainer& getContainer() const;
                    int getIndex() const;
            };

            class SideCrossIterator {
                private:
                    MagicalContainer * container;
                    int index;

                public:
                    SideCrossIterator() : container(nullptr), index(0)  {};
                    SideCrossIterator(MagicalContainer&);
                    SideCrossIterator(MagicalContainer&, int);
                    SideCrossIterator(const SideCrossIterator&);
                    SideCrossIterator(SideCrossIterator&&) = default;
                    SideCrossIterator& operator=(SideCrossIterator&&) = default;
                    ~SideCrossIterator() { };

                    SideCrossIterator& operator=(const SideCrossIterator&);
                    bool operator==(const SideCrossIterator&) const;
                    bool operator!=(const SideCrossIterator&) const;
                    bool operator>(const SideCrossIterator&) const;
                    bool operator<(const SideCrossIterator&) const;
                    int operator*() const;
                    SideCrossIterator& operator++();

                    SideCrossIterator begin() const;
                    SideCrossIterator end() const;

                    MagicalContainer& getContainer() const;
                    int getIndex() const;
            };

            class PrimeIterator {
                private:
                    MagicalContainer * container;
                    int index;

                public:
                    PrimeIterator() : container(nullptr), index(0)  {};
                    PrimeIterator(MagicalContainer&);
                    PrimeIterator(MagicalContainer&, int);
                    PrimeIterator(const PrimeIterator&);
                    PrimeIterator(PrimeIterator&&) = default;
                    PrimeIterator& operator=(PrimeIterator&&) = default;
                    ~PrimeIterator() { };

                    PrimeIterator& operator=(const PrimeIterator&);
                    bool operator==(const PrimeIterator&) const;
                    bool operator!=(const PrimeIterator&) const;
                    bool operator>(const PrimeIterator&) const;
                    bool operator<(const PrimeIterator&) const;
                    int operator*() const;
                    PrimeIterator& operator++();

                    PrimeIterator begin() const;
                    PrimeIterator end() const;

                    MagicalContainer& getContainer() const;
                    int getIndex() const;
            };
    };

}