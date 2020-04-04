//
// Created by yhzhan on 3/23/2020.
//

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <iostream>
#include <vector>
namespace quick_sort {
    enum class PivotPolicy : int {
        BEGIN = 0, END=1, MIN_BEGIN_END_MID=2
    };
    enum class PartitionType { WildRight, WildMiddle };

    class Partition {
    public:
        virtual int partition(std::vector<int> &vec, PivotPolicy policy, int start, int end, int &cnt_compare) = 0;
        int getPivot(const std::vector<int> &vec, PivotPolicy policy, int start, int end);
        static Partition *get();
    };

    /*
     * Incrementally construct three divisions during partition (from left to right)
     * 1. the region where elements are less than pivot value
     * 2. the region where elements have not been examined
     * 3. the region where elements are greater than pivot value
     * The region #2 gradually shrink until vanishing
     */
    class PartitionWildRight: public Partition {
    public:
        PartitionWildRight() {
            std::cout << "PartitionWildRight is constructed" << std::endl;
        }
        int partition(std::vector<int> &vec, PivotPolicy policy, int start, int end, int &cnt_compare) override;
    };

    /*
     * Incrementally construct three divisions during partition (from left to right)
     * 1. the region where elements are less than pivot value
     * 2. the region where elements are greater than pivot value
     * 3. the region where elements have not been examined
     * The region #3 gradually shrink until vanishing
     */
    class PartitionWildMiddle: public Partition {
    public:
        PartitionWildMiddle() {
            std::cout << "PartitionWildMiddle is constructed" << std::endl;
        }
        int partition(std::vector<int> &vec, PivotPolicy policy, int start, int end, int &cnt_compare) override;
    };

    void quickSortImpl(std::vector<int> &vec, PivotPolicy policy, int start, int end, int &cnt_compare);
    void quickSort(std::vector<int> &vec, PivotPolicy policy, int &cnt_compare);
}
#endif //QUICK_SORT_H
