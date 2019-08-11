/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Chiyuan Zhang, Soeren Sonnenburg
 */

#include <shogun/multiclass/tree/BalancedConditionalProbabilityTree.h>

using namespace shogun;

CBalancedConditionalProbabilityTree::CBalancedConditionalProbabilityTree()
	:m_alpha(0.4)
{
	SG_ADD(&m_alpha, "m_alpha", "Trade-off parameter of tree balance");
}

void CBalancedConditionalProbabilityTree::set_alpha(float64_t alpha)
{
	if (alpha < 0 || alpha > 1)
		error("expect 0 <= alpha <= 1, but got {:g}\n", alpha);
	m_alpha = alpha;
}

bool CBalancedConditionalProbabilityTree::which_subtree(bnode_t *node, SGVector<float32_t> ex)
{
	float64_t pred = predict_node(ex, node);
	float64_t depth_left = tree_depth(node->left());
	float64_t depth_right = tree_depth(node->right());

	float64_t cnt_left = CMath::pow(2.0, depth_left);
	float64_t cnt_right = CMath::pow(2.0, depth_right);

	float64_t obj_val = (1-m_alpha) * 2 * (pred-0.5) + m_alpha * CMath::log2(cnt_left/cnt_right);

	if (obj_val > 0)
		return false; // go right
	return true; // go left
}

int32_t CBalancedConditionalProbabilityTree::tree_depth(bnode_t *node)
{
	int32_t depth = 0;
	while (node != NULL)
	{
		depth++;
		node = node->left();
	}

	return depth;
}
