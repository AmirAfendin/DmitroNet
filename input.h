#ifndef INPUT_H
#define INPUT_H


class Input
{
public:
    Input(){};
    Input(int inValue, float inActivation);

    int value = 0;
    float activation = 0.0f;
};

#endif // INPUT_H
