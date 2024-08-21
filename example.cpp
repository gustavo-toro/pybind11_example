// pybind includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
#include <memory>
#include <iostream>

// namespace to use the bindings
namespace py = pybind11;

class MatchIterator {
public:
    // constructor
    MatchIterator(std::string_view document) : document_(document) {}

    // function accessible in the python module
    std::string get_document() { return std::string(document_); }

    std::string_view document_;
    MatchIterator(const MatchIterator&) = delete;
    MatchIterator(MatchIterator&&) = delete;
};


// This function returns an object
std::unique_ptr<MatchIterator> finditer(std::string_view document) {
    std::cout << "[finditer] address: " << &document << std::endl;
    return std::make_unique<MatchIterator>(document);
}


// We define all the functions we want to export
PYBIND11_MODULE(example, m) {
    // Optional module docstring
    m.doc() = "pybind11 example";

    // The class MatchIterator and a class function
    py::class_<MatchIterator>(m, "MatchIterator")
        .def("get_document", &MatchIterator::get_document);

    // Just a function
    m.def("finditer", &finditer);
}
