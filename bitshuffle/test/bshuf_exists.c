#include <hdf5.h>
#include <stdlib.h>


int main()
{
    H5open();
    hid_t plist = H5Pcreate(H5P_DATASET_CREATE);
    if(plist<0)
    {
        fprintf(stderr,"Could not create property list!\n");
        return 1;
    }
        
    unsigned int params[] = {0,3,1,0,2};
    if(H5Pset_filter(plist,(H5Z_filter_t)32008,H5Z_FLAG_MANDATORY,(size_t)5,params)<0)
    {
        fprintf(stderr,"Failed to load filter!\n");
        return 1;
    }

    htri_t error = H5Zfilter_avail((H5Z_filter_t)32008);

    if(error==0) 
    {
        fprintf(stderr,"Could not find bitshuffle filter!\n");
        return 1;
    }
    else if(error<0)
    {
        fprintf(stderr,"Filter search failed!");
        return 1;
    }

    fprintf(stderr,"Bitshuffle filter found!\n");
    return 0;
};
