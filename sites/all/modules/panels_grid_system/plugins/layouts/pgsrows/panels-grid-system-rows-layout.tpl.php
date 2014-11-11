<?php
/**
 * @file
 * Template for the "default" row grid for Panels Grid System.
 */
?>
<div class="panel-display pgs-rows-layout clearfix" <?php if (!empty($css_id)) : print "id=\"$css_id\""; endif; ?>>
  <?php $num_rows = empty($settings['num_rows']) ? 3 : $settings['num_rows']; ?>
  <?php for ($i = 1; $i <= $num_rows; $i++) : ?>
    <?php if (!empty($content["r$i"])): ?>
      <div class="panel-panel">
        <div class="pgs-rows-layout-row">
          <?php print $content["r$i"]; ?>
        </div>
      </div>
    <?php endif; ?>
  <?php endfor; ?>
</div>
