WHAT DOES THIS MODULE DO?
Panels Grid System is two things:

A panels style plugin: The style will let you choose how many columns you want
your pane to span. It works well with Panels in-place-editor, so you have kind
of a WYSIWYG layout functionality.

A panels layout: THe layout will let you choose how many one-column rows you
want in your display. You can have between 1 and 12 rows. Why would I want so
many rows when I have a "WYSIWYG" layout functionality you ask? The rows are
basically line breaks, so you might need a lot of them.

HOW TO INSTALL.
* Enable the module like you would any module.  Go to a panels page or create
* one. Set the style to "Grid system columns" on a couple of panes in the panel
* page. Now the panes float up next to each other.  If you want the rows layout
* just choose that for the page.

OVERRIDING GRID SIZES
The CSS for this module uses a 12-column, 5px padding, 960 grid. You can easily
override this by copying the style sheet 'grid-system-columns.css' from this
module's css folder to your theme. Don't forget to add the filename to the
theme's .info file.  To override the grid background, make an image that is
your padding-column-padding and override the background image in the
grid-system-background.css file.

If you are already using a style on the page you should be able to still get
the benefit of the grid column layout by applying the classes
grid-system-column and pgs-span-xx (xx is number of columns) directly to the
pane from the CSS properties setting on the pane.


STUFF THAT WOULD BE NICE TO HAVE:
An interface where you can specify column
width, number of columns, and gutter width instead of having to override style
sheets.
