//
// Created by yhzhan on 3/23/2020.
//

#include "quick_sort.h"

namespace {
    void swap(std::vector<int> &vec, int i, int j) {
        if (i == j) {
            return;
        }
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
}

namespace quick_sort {
    // PartitionType g_partitionType = PartitionType::WildMiddle;
    PartitionType g_partitionType = PartitionType::WildRight;
    Partition *Partition::get()
    {
        Partition *ret = nullptr;
        switch (g_partitionType) {
            case PartitionType::WildRight: {
                static PartitionWildRight partitioner1;
                ret = &partitioner1;
                break;
            }
            case PartitionType::WildMiddle: {
                static PartitionWildMiddle partitioner2;
                ret = &partitioner2;
                break;
            }
            default: {
                ret = nullptr;
            }
        }
        return ret;
    }

    void quickSort(std::vector<int> &vec, PivotPolicy policy, int &cnt_compare) {
        size_t sz = vec.size();
        if (vec.empty() || sz == 1) {
            return;
        }
        quickSortImpl(vec, policy, 0, sz - 1, cnt_compare);
    }

    void quickSortImpl(std::vector<int> &vec, PivotPolicy policy, int start, int end, int &cnt_compare) {
        if (start < 0 || end >= vec.size() || start >= end) { return; }
        int pivotIdx = Partition::get()->partition(vec, policy, start, end, cnt_compare);
        quickSortImpl(vec, policy, start, pivotIdx - 1, cnt_compare);
        quickSortImpl(vec, policy, pivotIdx + 1, end, cnt_compare);
    }

    int Partition::getPivot(const std::vector<int> &vec, PivotPolicy policy, int start, int end)
    {
        int pivot = start;
        if (policy == PivotPolicy ::BEGIN) {
            pivot = start;
        } else if (policy == PivotPolicy::END) {
            pivot = end;
        } else if (policy == PivotPolicy::MIN_BEGIN_END_MID) {
            auto mid = (start+end)/2;
            auto startVal = vec[start];
            auto endVal = vec[end];
            auto midVal = vec[mid];
            if (startVal < endVal) {
                if (midVal < startVal) {
                    pivot = start;
                } else if (endVal < midVal) {
                    pivot = end;
                } else {
                    pivot = mid;
                }
            } else if (endVal <= startVal) {
                if (midVal < endVal) {
                    pivot = end;
                } else if (startVal < midVal) {
                    pivot = start;
                } else {
                    pivot = mid;
                }
            }
        }
        return pivot;
    }

    int PartitionWildRight::partition(std::vector<int> &vec, PivotPolicy  policy, int start, int end, int &cnt_compare) {
        if (start < 0 || end >= vec.size() || start > end) { throw 999; }
        cnt_compare += end - start;
        int ret = -1;
        int pivot = getPivot(vec, policy, start, end);
        int pivotValue = vec[pivot];
        swap(vec, start, pivot);
        int i = start+1;
        int j = start+1;
        while (true) {
            if (j >= vec.size()) {
                break;
            }
            if (pivotValue <= vec[j]) {
                ++j;
            } else if (vec[j] < pivotValue) {
                swap(vec, i, j);
                ++i;
                ++j;
            }
        }
        swap(vec, start, i-1);
        ret = i-1;
        return ret;
    }

    int PartitionWildMiddle::partition(std::vector<int> &vec, PivotPolicy policy, int start, int end, int &cnt_compare)
    {
        if (start < 0 || end >= vec.size() || start > end) { throw 999; }
        cnt_compare += end - start;
        int ret = -1;
        int pivot = getPivot(vec, policy, start, end);
        int pivotValue = vec[pivot];
        // swap the pivot to the 1st position
        swap(vec, start, pivot);

        int i = start+1;
        int j = end;
        while (true) {
            if (vec[i] <= pivotValue) {
                ++i;
            } else if (vec[i] > pivotValue) {
                swap(vec, i, j);
                --j;
            }
            if (i > j) {
                break;
            }
        }
        swap(vec, start, i-1);
        ret = i-1;
        return ret;
    }
}
