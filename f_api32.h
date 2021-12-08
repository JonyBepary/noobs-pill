int fileExists(TCHAR *PATH)
{
    // structure in minwinbase.h
    WIN32_FIND_DATA FindFileData;
    // structure in fileapi.h
    HANDLE handle = FindFirstFile(PATH, &FindFileData);
    int found = handle != INVALID_HANDLE_VALUE;
    if (found)
    {
        //FindClose(&handle); this will crash
        FindClose(handle);
    }
    return found;
}
