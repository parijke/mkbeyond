<?php
/**
 * @file
 * Layout template for the Foundation grid system.
 */
?>
<div class="panel-display pgs-foundation-layout container" <?php if (!empty($css_id)) : print "id=\"$css_id\""; endif; ?>>
  <?php $num_rows = empty($settings['num_rows']) ? 6 : $settings['num_rows']; ?>
  <div class="row">
    <?php for ($i = 1; $i <= $num_rows; $i++) : ?>
      <?php if($content["r$i"]): ?>
        <?php print $content["r$i"]; ?>
      <?php endif; ?>
    <?php endfor; ?>
  </div>
</div>
