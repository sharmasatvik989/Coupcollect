# Coupcollect
The following code is an implementation of the Coupon Collector Problem.
1. The code determines the expectation of the number Cj of elements that need to
   be drawn from & (with replacement), till one first obtains a collection
   with j different coupons. 
2. Quantity E(C,,) is of particular interest since it represents the expected time to obtain a full collection. The solution of this problem in the equiprobable        case is a
    classical exercise: One needs to draw one element to gather a collection of cardinality
    1; then m/(m - 1) draws are necessary on the average to gather a new element etc.
    In this way, one finds where & is the mth harmonic number. In the same vein, E(Cj) =m(&-&-j).
    In the general case of a nonuniform probability distribution.
