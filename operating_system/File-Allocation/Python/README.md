<h1>File Allocation</h1>

<h5>
    The allocation methods define how the files are stored in the disk blocks. There are three main disk space or file allocation methods

  <br>  1. Contiguous Allocation 
  <br>  2. Linked Allocation 
  <br>  3. Indexed Allocation 
    
  <br>  The main idea behind these methods is to provide: 

  <br>  1. Efficient disk space utilization. 
  <br>  2. Fast access to the file blocks. 
</h5>

<h3> 1. Contiguous Allocation </h3>
<h6>
    In this scheme, each file occupies a contiguous set of blocks on the disk. For example, if a file requires n blocks
    and is given a block b as the starting location, then the blocks assigned to the file will be: b, b+1, b+2,……b+n-1.
    This means that given the starting block address and the length of the file (in terms of blocks required), we can 
    determine the blocks occupied by the file.<br/>
    
    The directory entry for a file with contiguous allocation contains

  <br>  1. Address of starting block 
  <br>  2. Length of the allocated portion. 
</h6>

<h3> 2. Linked List Allocation </h3>
<h6>
    In this scheme, each file is a linked list of disk blocks which need not be contiguous. The disk blocks can be 
    scattered anywhere on the disk. The directory entry contains a pointer to the starting and the ending file block. 
    <br/>

    Each block contains a pointer to the next block occupied by the file
    
</h6>

<h3> 3. Indexed Allocation </h3>
<h6>
    In this scheme, a special block known as the Index block contains the pointers to all the blocks occupied by a file.
    Each file has its own index block. The ith entry in the index block contains the disk address of the ith file block.
    <br/>
</h6>