(function ($) {

  Drupal.behaviors.gridSystemIPE = {
    attach: function (context, settings) {

      if ($('.grid-system-column').length > 0) {
        // Set a width directly here taken from the pane's width. This is to
        // give box-sizing a chance to calculate its size on the draggable
        // panes.
        $('.grid-system-column').each(function(index) {
          $(this).parents('.panels-ipe-portlet-marker').addClass('pgs-ipe-wrapper').width($(this).width());
        });
      }
    }
  };

})(jQuery);
