#include "Big_number.h"
#include <algorithm>

Big_number::Big_number():valarray_ptr{std::make_unique<std::valarray<int>>(1)}
{
}

Big_number::Big_number(std::string num):valarray_ptr{ std::make_unique<std::valarray<int>>(num.length())}
{
    std::transform(num.begin(),num.end(),begin(*valarray_ptr),[](const auto& a){ return std::stoi(std::string{a},nullptr,10);});
}

Big_number::Big_number(const Big_number& b):valarray_ptr{ std::make_unique<std::valarray<int>>(b.size())}
{
    std::copy( std::begin(*(b.valarray_ptr)), std::end(*(b.valarray_ptr)), std::begin(*valarray_ptr));
}

Big_number& Big_number::operator=(const Big_number& b)
{
    if(&b != this)
    {
        valarray_ptr->resize(b.size());
        std::copy( std::begin(*(b.valarray_ptr)), std::end(*(b.valarray_ptr)), std::begin(*valarray_ptr));
    }
    return *this;
}

Big_number::Big_number(Big_number&& b):valarray_ptr{std::make_unique<std::valarray<int>>(1)}
{
    std::swap(valarray_ptr, b.valarray_ptr);
}

Big_number& Big_number::operator=(Big_number&& b)
{
    valarray_ptr.reset(b.valarray_ptr.release());
    b.valarray_ptr=std::make_unique<std::valarray<int>>(1);
    return *this;
}


std::string Big_number::str() const
{
    std::string tmp_str(valarray_ptr->size(),'0');
    std::transform(begin(*valarray_ptr), end(*valarray_ptr), tmp_str.begin(), [](const auto& a){  return std::to_string(a).c_str()[0]; });
    return tmp_str;
}

Big_number::~Big_number()
{
    //dtor
}

size_t Big_number::size() const
{
    return valarray_ptr->size();
}


void Big_number::clear()
{
    valarray_ptr->resize(1);
}
