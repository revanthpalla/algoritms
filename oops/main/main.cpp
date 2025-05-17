#include <iostream>
#include <vector>
#include "H5Cpp.h"
using namespace std;

void write_dataset() {
    // open hdf file
    H5::H5File* h5file = new H5::H5File("/Users/revanthpalla/code/oops/main/int_vector.h5", H5F_ACC_TRUNC);
    // create a 1D vector
    vector<int> v = { 12, 13, 14, 15, 16 };
    // define dataspace dimensions
    hsize_t dims[1] = { v.size() };  // 1D array
    H5::DataSpace dataspace(1, dims);
    // create a dataset
    H5::DataSet* dataset = new H5::DataSet(h5file->createDataSet("monotonic_array", H5::PredType::NATIVE_INT, dataspace));
    // write data
    dataset->write(v.data(), H5::PredType::NATIVE_INT);
    delete dataset;
    delete h5file;
}

void read_dataset() {
    // open hdf5 file
    H5::H5File file("/Users/revanthpalla/code/oops/main/int_vector.h5", H5F_ACC_RDONLY);
    // open dataset
    H5::DataSet dataset = file.openDataSet("monotonic_array");
    // Get the dataspace and determine size
    H5::DataSpace dataspace = dataset.getSpace();
    hsize_t dims[1]; // assuming it's a 1D vector
    int ndims = dataspace.getSimpleExtentDims(dims, nullptr);
    if (ndims != 1) {
        std::cerr << "Dataset is not 1-dimensional!" << std::endl;
        return;
    }
    std::vector<int> data(dims[0]);
    dataset.read(data.data(), H5::PredType::NATIVE_INT);
    // Step 5: Print contents
    std::cout << "Read vector from HDF5 file: ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    cout << "HDF Example!" << endl;
    write_dataset();
    read_dataset();
    return 0;
}