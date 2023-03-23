#include "entity.h"
#include "crudl.h"
#include <stdlib.h>
// Function of reading a record of a given type from a file by its serial number.
entity* read_record_from_file(FILE *pfile, int index, entity e)
{
    // Calculation of the offset at which desired entry should be located from the beginning of the file.
    int offset = index * sizeof(entity);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Reading a record of the specified type from a file.
    entity* record = malloc(sizeof(entity));
    fread(record, sizeof(entity), 1, pfile);

    // For safety reasons, we return the file position pointer to the beginning of the file.
    rewind(pfile);

    // Return read record
    return record;
}

// Function of writing a record of the specified type to the file at the specified serial number.
void write_record_in_file(FILE *pfile, const entity *record_to_write, int index)
{
    // Calculation of the offset at which the required record should be located from the beginning of the file.
    int offset = index * sizeof(entity);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Write a record of the specified type to a file.
    fwrite(record_to_write, sizeof(entity), 1, pfile);

    // Just in case, force the I/O subsystem to write the contents of its buffer to a file right now.
    fflush(pfile);

    // For safety reasons, return the file position pointer to the beginning of the file.
    rewind(pfile);
}

// Function of mutual transfer of two records in the file by their indexes.
void swap_records_in_file(FILE *pfile, entity* t1, entity* t2, int index1, int index2)
{
    int read1 = !t1;
    int read2 = !t2;
    // Read both records from file to variables
    if (read1) t1 = read_record_from_file(pfile, index1);
    if (read2) t2 = read_record_from_file(pfile, index2);

    // Rewrite records in file
    write_record_in_file(pfile, t1, index2);
    write_record_in_file(pfile, t2, index1);

    if (read1) free(t1);
    if (read2) free(t2);
}

// Function to get file size in bytes.
int get_file_size_in_bytes(FILE *pfile)
{
    int size = 0;
    fseek(pfile, 0, SEEK_END);    // Move the position pointer to the end of the file.
    size = ftell(pfile);          // Read the number of bytes from the beginning of the file to the current position pointer.
    rewind(pfile);                // For safety reasons, move the position pointer back to the beginning of the file.
    return size;
}

// Function to get count of records in file
int get_records_count_in_file(FILE *pfile)
{
    return get_file_size_in_bytes(pfile) / sizeof(entity);
}
