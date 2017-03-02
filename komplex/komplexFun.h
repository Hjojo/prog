typedef struct {double re,im;} komplex;

void komplex_set(komplex* z, double x, double y);
komplex komplex_new(double x, double y);
komplex komplex_add(komplex a, komplex b);
komplex komplex_sub(komplex a, komplex b);
komplex komplex_conjugate(komplex z);
