#include "../include/file_utils.h"
#include<stdio.h>
#include<stdlib.h>

/* */
int createBinaryFile(const char* filename){
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL){
        return -1;
    }
    fclose(fp);
    return 0;
}
/* */
int readRecord(const char* filename, int index, Record* r)
{

    FILE *fp = fopen(filename, "rb");

    if (fp == NULL)
        return -1;

    fseek(fp, index * sizeof(Record), SEEK_SET);

    if (fread(r, sizeof(Record), 1, fp) != 1) {
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

/* */
int countRecords(const char *filename)
{
    if (filename == NULL)
    {
        return -1;
    }
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return -1;
    }
    if (fseek(fp, 0, SEEK_END) != 0)
    {
        fclose(fp);
        return -1;
    }
    long pos = ftell(fp); // was int — ftell returns long
    if (pos == -1L)
    {
        fclose(fp);
        return -1;
    }
    int count = pos / sizeof(Record);
    fclose(fp);
    return count;
}
/* */
int appendRecord(const char* filename, Record* r){
    FILE *fp = fopen(filename, "ab");
    if(fp == NULL){
        return -1;
    }

    size_t write_count = fwrite(r, sizeof(Record), 1, fp);

    fclose(fp);

    if(write_count != 1){
        return -1;
    }

    return 0;
}
/* */
int searchRecordById(const char* filename, int id, Record* result)
{
    FILE* f = fopen(filename, "rb");
    if (f == NULL)
    {
        return -1;
    }

    Record temp;
    int index = 0;

    while (fread(&temp, sizeof(Record), 1, f) == 1)
    {
        if (temp.id == id)
        {
            *result = temp;
            fclose(f);
            return index;
        }

        index++;
    }

    fclose(f);
    return -1; // not found
}
/* */
int updateRecord(const char* filename, int index, Record* newData)
{
    FILE* f = fopen(filename, "r+b");
    if (f == NULL)
    {
        return -1;
    }

    /* Move to the exact position of the record */
    if (fseek(f, index * sizeof(Record), SEEK_SET) != 0)
    {
        fclose(f);
        return -1;
    }

    /* Overwrite the old record */
    fwrite(newData, sizeof(Record), 1, f);

    fclose(f);
    return 0;
}
/* read from the first file print in the second file */
int copyBinaryFile(const char* src, const char* dest)
{
    FILE* in = fopen(src, "rb");
    if (in == NULL)
    {
        return -1;
    }

    FILE* out = fopen(dest, "wb");
    if (out == NULL)
    {
        fclose(in);
        return -1;
    }

    int buffer;

    while (fread(&buffer, sizeof(int), 1, in) == 1)
    {
        fwrite(&buffer, sizeof(int), 1, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}