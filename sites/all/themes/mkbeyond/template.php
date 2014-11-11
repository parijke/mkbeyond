<?php
/**
 * @file
 * template.php
 */

 function mkbeyond_menu_tree__primary(&$variables) {
	return '<ul class="menu nav navbar-nav pull-right">' . $variables['tree'] . '</ul>';
} 

/**
* Implements template_preprocess_html().
*/
function mkbeyond_preprocess_html(&$vars) {
  $_meta = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'Creator',
      'content' => 'Paul Rijke (http://www.mkbeyond.nl)',
    ),
  );
  drupal_add_html_head($_meta, 'my_meta');
}