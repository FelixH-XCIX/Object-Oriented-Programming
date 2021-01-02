#pragma once

template<typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) 
{
    while (first <= last) 
    {
        int mid = first + (last - first) / 2;

        if (a[mid] == key) {
            found = true;
            location = mid;
            return;
        }

        if (a[mid] < key) {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
    }
    found = false;
    location = -1;
    return;
}

template<typename T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
    if (last >= first) {
        int mid = first + (last - first) / 2;

        if (a[mid] == key) {
            found = true;
            location = mid;
            return;
        }

        if (a[mid] > key) {
            return RecBinarySearch(a, first, mid - 1, key, found, location);
        }
        else {
            return RecBinarySearch(a, mid + 1, last, key, found, location);
        }
    }
    found = false;
    location = -1;
    return;
}