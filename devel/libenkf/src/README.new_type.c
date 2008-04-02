/**
The two files README.new_type.c and README.new_type_config.c (along
with the corresponding header files) are meant to serve as a
documentation and reference on how to add new object types to the enkf
system.


new_type.c (should read README.new_type.h first).
==========
For all the enkf objects we have split the member spesific data, and
the configuration information in two different files (objects):

                        ______________
                       |              |
      _________________| Config       |_______________
     |                 | information  |               |
     |                /|______________|\              |
     |               /        |         \             |
     |              /         |          \            |
     |             /          |           |           |
     |            |           |           |           |
    _|__        __|_         _|__        _|__        _|__  
   |    |      |    | 	    |    |      |    | 	    |    | 
   | 01 |      | 02 | 	    | 03 |      | 04 | 	    | 05 | 
   |____|      |____| 	    |____|      |____| 	    |____| 


The figure shows an ensemble of 5 members (of some type); they all
have a pointer to a common configuration object. The though behind
this is that all members should share configuration information,
i.e. for instance all the members in a permeability field should have
the same active/inactive cells, all the relperm instances should use
the same relperm model e.t.c. This file is about implementing the data
members, i.e. the small boxes. The implementation of the config
object, is discussed in README.new_type_config.c.

The enkf object system is based on the enkf_node_type as a sort of
virtual class, this object has a void pointer which will point to the
actual data instance (i.e. for instance an instance of the type
"new_type" implemented here), along with several function pointers to
manipulate the data object. The definition of the function pointers
are in enkf_node.h. The functions we need (do not have to specify them
all) are:


1.  typedef void * (alloc_ftype) (const void *);
    --------------------------------------------

    This function takes a pointer to a config object of the right type
    (i.e. new_type_config_type in this case), reads the required
    configuration information from this object, and returns a new new_type
    instance.


2.  typedef void  (fread_ftype) ( void * , FILE * );
    ------------------------------------------------
    This function should take a pointer to a new_type object, and a
    stream opened for reading as input, and then read in data for the
    object from disk.


3.  typedef void  (fwrite_ftype) ( void * , FILE * );
    ------------------------------------------------
    This function should take a pointer to a new_type object, and a
    stream opened for writing as input, and then write the data from
    the object to disk. The two functions instances fread_ftype - and
    fwrite_ftype must of course match.

*/
