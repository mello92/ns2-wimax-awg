#include<math.h>
#include<stdlib.h>

static double table16[16] = {0.000212, 0.044467, 0.327070, 0.390380, 0.170797, 0.049427, 0.013169, 0.003272, 0.000855, 0.000246, 0.000046, 0.000008, 0.000001, 0.000000, 0.000000, 0.000000};

static double table15[15] = {0.000413, 0.057850, 0.363636, 0.380317, 0.148284, 0.037265, 0.008711, 0.002397, 0.000726, 0.000241, 0.000051, 0.000008, 0.000001, 0.000000, 0.000000};

static double table12[12] = {0.000668, 0.068453, 0.367716, 0.359951, 0.147371, 0.042277, 0.010313, 0.002502, 0.000501, 0.000072, 0.000009, 0.000000};

//from hongsuda's topology
static double table20[20] = {0.000310, 0.001993, 0.006046, 0.019854, 0.045055, 0.072606, 0.079511, 0.061733, 0.037823, 0.019340, 0.009756, 0.005144, 0.002635, 0.001085, 0.000363, 0.000108, 0.000036, 0.000013, 0.000004, 0.000001};


int Power_law_no_hops(double delta, double H);
int Inet_default_no_hops(int diameter);
double Binomial_aggregations(double mu, double p);