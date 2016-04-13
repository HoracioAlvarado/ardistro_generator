<?php
/**
* @file
* Template for the 1 column panel layout.
*
* This template provides a three column 25%-50%-25% panel display layout.
*
* Variables:
* - $id: An optional CSS id to use for the layout.
* - $content: An array of content, each item in the array is keyed to one
*   panel of the layout. This layout supports the following sections:
*   - $content['left']: Content in the left column.
*   - $content['middle']: Content in the middle column.
*   - $content['right']: Content in the right column.
*/
?>
<div class="clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; }?>>
	<!-- Imagen destacada -->
	<div class="panel-panel panel-col-first">
		<div class="inside"><?php print $content['destacado']; ?></div>
	</div>
	<!-- 	<div class="container"> -->
	<!-- 	<div class="row"> -->
	<div class="panel-panel">
		<div class="inside"><?php print $content['one']; ?></div>
	</div>
<!-- 		</div>
</div> -->
<!-- Editorial -->
<div class="_container" >
<div class="row">
	<div class="col-md-9"><?php print $content['editorial_one']; ?></div>
	<div class="col-md-3"><?php print $content['editorial_two']; ?></div>
</div>
</div>
<!-- / Editorial -->
<div class="panel-panel">
<div class="inside"><?php print $content['two']; ?></div>
</div>
<div class="panel-panel bg-grey">
<!-- 		<div class="container">
	<div class="row"> -->
		<div class="inside"><?php print $content['three']; ?></div>
	<!-- </div>
</div> -->
</div>
<div class="panel-panel">
<div class="inside"><?php print $content['four']; ?></div>
</div>
</div>