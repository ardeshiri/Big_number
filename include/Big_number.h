#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H
#include <valarray>
#include <memory>

class Big_number
{
    public:
        Big_number();
        Big_number(std::string num);
        Big_number(const Big_number& b);
        Big_number& operator=(const Big_number& b);
        Big_number(Big_number&& b);
        Big_number& operator=(Big_number&& b);

        ~Big_number();
        std::string str() const;
        size_t size() const;
        void clear();


    protected:

    private:
    std::unique_ptr<std::valarray<int>> valarray_ptr;
};

#endif // BIG_NUMBER_H
