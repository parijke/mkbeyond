<?php
/**
 * @file
 * Layout template for the 960.gs grid system.
 */
?>
<div class="panel-display pgs-ninesixty-layout container container_12" <?php if (!empty($css_id)) : print "id=\"$css_id\""; endif; ?>>
  <?php $num_rows = empty($settings['num_rows']) ? 3 : $settings['num_rows']; ?>
  <?php for ($i = 1; $i <= $num_rows; $i++) : ?>
    <?php print $content["r$i"]; ?>
  <?php endfor; ?>
</div>
