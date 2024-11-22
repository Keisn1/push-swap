#include "test_push_swap.hpp"

void assert_equal_stack(t_stack *got, t_stack *want) {
    while (got != NULL && want != NULL) {
		EXPECT_EQ(*(int*)(got->content), *(int*)(want->content));
		got = got->next;
		want = want->next;
	}
	EXPECT_EQ(got, want);
}


void assert_equal_state(t_state got, t_state want) {
	assert_equal_stack(got.a, want.a);
	assert_equal_stack(got.b, want.b);
	EXPECT_EQ(got.size_a, want.size_a);
	EXPECT_EQ(got.size_b, want.size_b);
}

void clear_stacks(t_state got, t_state want) {
	ft_lstclear(&(got).a, free);
	ft_lstclear(&(got).b, free);
	ft_lstclear(&(want).a, free);
	ft_lstclear(&(want).b, free);
}

t_stack *create_stack(std::vector<int> nbrs) {
	if (nbrs.size() == 0)
		return NULL;

	int *x = (int*)malloc(sizeof(int));
	*x = nbrs[0];
	t_stack *stack = ft_lstnew(x);
	for (size_t i = 1; i < nbrs.size(); ++i) {
		x = (int*)malloc(sizeof(int));
		*x = nbrs[i];
		ft_lstadd_back(&stack, ft_lstnew(x));
	}

	return stack;
}

int countNewlines(const std::string& text) {
    int newlineCount = 0;
    for (char ch : text) {
        if (ch == '\n') {
            ++newlineCount;
        }
    }
    return newlineCount;
}
