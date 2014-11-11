<?php
/**
 * @file
 * Template for Mars.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display mars clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

<div class="container-fluid slideshow">
  <div class="row">
    <!--div class="col-md-12 layer_slider panel-panel"-->
      <div class="panel-panel-inner">
        <?php print $content['layer_slider']; ?>
      </div>
    <!--/div-->
  </div>
</div>
  
  <div class="container">
    <div class="row">
      <div class="content panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['contentmain']; ?>
        </div>
      </div>
    </div>
  </div>

  <div class="footer">
    <div class="container">
      <div class="row">
        <div class="col-md-4 footer1 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['footer1']; ?>
          </div>
        </div>
        <div class="col-md-4 footer2 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['footer2']; ?>
          </div>
        </div>
        <div class="col-md-4 footer3 panel-panel">
          <div class="panel-panel-inner">
            <?php print $content['footer3']; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
  
</div><!-- /.mars -->
