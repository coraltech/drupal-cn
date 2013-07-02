<?php
/**
 * @file
 * Template for a 2 column autocomplete item layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 */
?>
<table class="panels-autocomplete autocomplete-item" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <tr class="item-row">
    <td class="col col-left"><?php print $content['left']; ?></td>
    <td class="col col-right"><?php print $content['right']; ?></td>
  </tr>
</table>