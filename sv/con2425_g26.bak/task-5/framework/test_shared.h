#pragma once

#include <sstream>
#include <vector>

// feel free to uncomment if you think there's a bug with the framework (that's always possible)
// #define FRAMEWORK_DEBUG

#define frameworkDebug(...) do { if (__CONTest::isFrameworkDebug) fprintf(stderr, "[framework] " __VA_ARGS__); } while(0)

namespace __CONTest {
    extern const bool isFrameworkDebug;

    template <typename... T>
    std::string concatenate(T&&... args)
    {
        std::stringstream ss;
        ((ss << args), ...);
        return ss.str();
    }

    struct ContextHandle {
        private:
            static std::vector<std::string> _activeContexts;
        
        public:
            template <typename... T> ContextHandle(T&&... args) { _activeContexts.emplace_back(concatenate(std::forward<T>(args)...)); }
            ~ContextHandle() { _activeContexts.pop_back(); }
            static std::string contextSummary() {
                std::stringstream ss;
                for (std::string const& ctx : _activeContexts) {
                    ss << "\n- with: " << ctx;
                }
                return ss.str();
            }
    };
}

#define assertThat(what, cond) do { if (!(cond)) { \
    if (__CONTest::isFrameworkDebug) { \
        fprintf(stderr, "[!! framework] >> point of assertion failure!\n"); \
    } \
    throw __CONTest::concatenate("Assertion \"", what, "\" (", #cond, ") fails.", __CONTest::ContextHandle::contextSummary()); \
} } while(0)

#define assertSuccess(call) do { if (quib_status status = call; status != NO_ERROR) { \
    if (__CONTest::isFrameworkDebug) { \
        fprintf(stderr, "[!! framework] >> point of assertion failure!\n"); \
    } \
    throw __CONTest::concatenate("Operation failed (", quib_status_str(status), "): ", #call, __CONTest::ContextHandle::contextSummary()); \
} } while(0)

#define assertEquals(what, actual, expected) do { \
    auto&& left = (actual); auto&& right = (expected); \
    if (!(left == right)) { \
        if (__CONTest::isFrameworkDebug) { \
            fprintf(stderr, "[!! framework] >> point of assertion failure!\n"); \
        } \
        throw __CONTest::concatenate("Assertion \"", what, "\" (", #actual, " == ", #expected, ") fails:\n", \
            "-) actual:   ", #actual, " = ", std::to_string(left), "\n", \
            "-) expected: ", #expected, " = ", std::to_string(right), __CONTest::ContextHandle::contextSummary()); \
    } \
} while(0)
