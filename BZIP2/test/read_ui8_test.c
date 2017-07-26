#include <hdf5.h>
#include <stdlib.h>

static const size_t n=10;
static const uint8_t ref_data[]={0,1,2,3,4,5,6,7,8,9};
static const char *fname="ui8_data.h5";


int main()
{
    hid_t fid = H5Fopen(fname,H5P_DEFAULT,H5P_DEFAULT);
    if(fid<0) return 1;

    hid_t dset = H5Dopen(fid,"/data",H5P_DEFAULT);
    if(dset<0) return 1;
    
    uint8_t data[n];
    hid_t mem_type = H5Tcopy(H5T_NATIVE_UINT8);
    if(H5Dread(dset,mem_type,H5S_ALL,H5S_ALL,H5P_DEFAULT,(void*)(data))<0)
        return 1;
    
    size_t index;
    for(index=0;index<n;index++)
    {
        if(ref_data[index]!=data[index])
            return 1;
    }



    return 0;
}
