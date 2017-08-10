#include <hdf5.h>
#include <stdlib.h>

#define NX 3
#define NY 4
#define NZ 5
static const char *fname="bslz4_3x4x5_testdata.h5";


int main()
{
    hid_t fid = H5Fopen(fname,H5F_ACC_RDONLY,H5P_DEFAULT);
    if(fid<0) return 1;

    hid_t dset = H5Dopen(fid,"/data_uint32",H5P_DEFAULT);
    if(dset<0) return 1;
    
    uint8_t data[NX*NY*NZ];
    hid_t mem_type = H5Tcopy(H5T_NATIVE_UINT8);
    if(H5Dread(dset,mem_type,H5S_ALL,H5S_ALL,H5P_DEFAULT,(void*)(data))<0)
        return 1;
    
    size_t index;
    for(index=0;index<NX*NY*NZ;index++)
    {
        if(data[index]!=(uint32_t)index) return 1;
    }

    return 0;
}
