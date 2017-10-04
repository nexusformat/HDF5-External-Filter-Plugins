import h5py


f = h5py.File("bitshuffle_file.h5","w")
filter_id = 32008
d1 = f.create_dataset("with_lz4",(100,100),
                      compression=filter_id,
                      compression_opts=(0,2))
d2 = f.create_dataset("without_lz4",(100,100),
                      compression=filter_id)