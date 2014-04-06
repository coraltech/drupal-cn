<?php

/**
 * @file
 * Default theme implementation to navigate books.
 *
 * Presented under nodes that are a part of book outlines.
 *
 * Available variables:
 * - $tree: The immediate children of the current node rendered as an unordered
 *   list.
 * - $current_depth: Depth of the current node within the book outline. Provided
 *   for context.
 * - $prev_url: URL to the previous node.
 * - $prev_title: Title of the previous node.
 * - $parent_url: URL to the parent node.
 * - $parent_title: Title of the parent node. Not printed by default. Provided
 *   as an option.
 * - $next_url: URL to the next node.
 * - $next_title: Title of the next node.
 * - $has_links: Flags TRUE whenever the previous, parent or next data has a
 *   value.
 * - $book_id: The book ID of the current outline being viewed. Same as the node
 *   ID containing the entire outline. Provided for context.
 * - $book_url: The book/node URL of the current outline being viewed. Provided
 *   as an option. Not used by default.
 * - $book_title: The book/node title of the current outline being viewed.
 *   Provided as an option. Not used by default.
 *
 * @see template_preprocess_book_navigation()
 *
 * @ingroup themeable
 */
?>
<?php if ($tree || $has_links): ?>
  <div id="book-navigation-<?php print $book_id; ?>" class="book-navigation clearfix">

    <?php if ($tree): ?>
      <div class="<?php print $tree_class; ?> tree">
        <?php print $tree; ?>  
      </div>
    <?php endif; ?>


    <?php if ($has_links): ?>

      <?php if ($prev_url): ?>
        <a href="<?php print $prev_url; ?>" class="<?php print $btn_class; ?> btn btn-prev page-previous nowrap" title="<?php print t('Go to: ') . $prev_title; ?>"><?php print t('Previous') ?></a>
      <?php endif; ?>
      
      <?php if ($next_url): ?>
        <a href="<?php print $next_url; ?>" class="<?php print $btn_class; ?> btn btn-next page-next nowrap" title="<?php print t('Go to: ') . $next_title; ?>"><?php print t('Next'); ?></a>
      <?php endif; ?>
      
      <?php if ($parent_url): ?> 
        <div class="book-parent">
          <a href="<?php print $parent_url; ?>" class="page-up" title="<?php print t('Go to: ') . $parent_title; ?>"><span class="arrow-up"></span></span></a>
        </div>
      <?php endif; ?>

    <?php endif; ?>

  </div>
<?php endif; ?>
