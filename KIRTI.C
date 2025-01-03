#include <stdio.h>
#include <windows.h>

// Thread function for reader
DWORD WINAPI reader(LPVOID arg) {
    int id = *(int*)arg;
    printf("Reader %d is reading\n", id);
    Sleep(1000); // Simulate reading
    printf("Reader %d finished reading\n", id);
    return 0;
}

// Thread function for writer
DWORD WINAPI writer(LPVOID arg) {
    int id = *(int*)arg;
    printf("Writer %d is writing\n", id);
    Sleep(1000); // Simulate writing
    printf("Writer %d finished writing\n", id);
    return 0;
}

int main() {
    HANDLE readers[3], writers[2];
    int reader_ids[3] = {1, 2, 3};
    int writer_ids[2] = {1, 2};

    // Create writer threads
    for (int i = 0; i < 2; i++) {
        writers[i] = CreateThread(NULL, 0, writer, &writer_ids[i], 0, NULL);
    }

    // Create reader threads
    for (int i = 0; i < 3; i++) {
        readers[i] = CreateThread(NULL, 0, reader, &reader_ids[i], 0, NULL);
    }

    // Wait for all threads to finish
    WaitForMultipleObjects(2, writers, TRUE, INFINITE);
    WaitForMultipleObjects(3, readers, TRUE, INFINITE);

    // Close thread handles
    for (int i = 0; i < 2; i++) {
        CloseHandle(writers[i]);
    }
    for (int i = 0; i < 3; i++) {
        CloseHandle(readers[i]);
    }

    return 0;
}
