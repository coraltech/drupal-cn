<?php
  // Primary theme tpl for the individual stat
  //  Override with coral_stat__[$stat_id].tpl.php
?>
<div class="coral-stat <?php if ($class): ?>stat-<?php print $class; ?><?php endif; ?>">
  <span class='statdata'><?php print $data; ?></span>
</div>