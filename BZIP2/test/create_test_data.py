#
# script used to create test data for BZIP2 readback test
#
from __future__ import print_function
import numpy
import tables


fname = 'ui8_data.h5'
shape = (10,)
atom = tables.UInt8Atom()
filters = tables.Filters(complevel=2,complib='bzip2')

f = tables.open_file(fname,'w')
a = f.create_carray(f.root,'data',atom,shape,filters=filters)
a[:] = numpy.arange(0,10,dtype='u8')
f.close()
