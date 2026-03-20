#pragma once

#include <climits>

namespace math {

    enum class StatusCode {
        SUCCESS = 0,
        DIVISION_BY_ZERO,
        OVERFLOW,
        INVALID_ARGUMENT
    };

    inline const char* statusCodeToString(StatusCode code) {
        switch (code) {
            case StatusCode::SUCCESS:           return "Success";
            case StatusCode::DIVISION_BY_ZERO:  return "Division by zero";
            case StatusCode::OVERFLOW:          return "Overflow";
            case StatusCode:: INVALID_ARGUMENT: return "Invalid argument";
            default:                            return "Unknown error";
        }
    }

    StatusCode add(int a, int b, int& result) {
        if (b > 0) {
            if (a > INT_MAX - b) {
                return StatusCode::OVERFLOW;
            } 
        } else if (b < 0) {
            if (a < INT_MIN - b) {
                return StatusCode::OVERFLOW;
            }   
        }

        result = a + b;
        return StatusCode::SUCCESS;
    }

    StatusCode subtract(int a, int b, int& result) {
        if (b < 0) {
            if (a > INT_MAX + b) {
                return StatusCode::OVERFLOW;
            }
        } else if (b > 0) {
            if (a < INT_MIN + b) {
                return StatusCode::OVERFLOW;
            }
        }

        result = a - b;
        return StatusCode::SUCCESS;
    }

    StatusCode multiply(int a, int b, int& result) {
        if (a == 0 || b == 0) {
            result = 0;
            return StatusCode::SUCCESS;
        }

        if (a > 0) {
            if (b > 0) {
                if (a > INT_MAX / b) {
                    return StatusCode::OVERFLOW;
                }
            } else {
                if (b < INT_MIN / a) {
                    return StatusCode::OVERFLOW;
                }
            }
        } else {
            if (b > 0) {
                if (a < INT_MIN / b) {
                    return StatusCode::OVERFLOW;
                }
            } else {
                if (a < INT_MAX / b) {
                    return StatusCode::OVERFLOW;
                }
            }
        }

        result = a * b;
        return StatusCode::SUCCESS;
    }

    StatusCode divide(int a, int b, int& result) {
        if (b == 0) {
            return StatusCode::DIVISION_BY_ZERO;
        }

        if (a == INT_MIN && b == -1) {
            return StatusCode::OVERFLOW;
        }

        result = a / b;
        return StatusCode::SUCCESS;
    }

    StatusCode power(int base, int exponent, int& result) {
        if (exponent < 0) {
            return StatusCode::INVALID_ARGUMENT;
        }

        result = 1;
        for (int i = 0; i < exponent; ++i) {
            int temp;
            StatusCode status = multiply(result, base, temp);
            if (status != StatusCode::SUCCESS) {
                return status;
            }
            result = temp;
        }

        return StatusCode::SUCCESS;
    }

    StatusCode factorial(int n, int& result) {
        if (n < 0) {
            return StatusCode::INVALID_ARGUMENT;
        }

        if (n > 12) {
            return StatusCode::OVERFLOW;
        }

        if (n <= 1) {
            result = 1;
            return StatusCode::SUCCESS;
        }

        int temp;
        StatusCode status = factorial(n - 1, temp);
        
        if (status != StatusCode::SUCCESS) {
            return status;
        }

        if (temp > INT_MAX / n) {
            return StatusCode::OVERFLOW;
        }

        result = n * temp;
        return StatusCode::SUCCESS;
    }

} // namespace math