.PHONY: clean All

All:
	@echo "----------Building project:[ QuadTree - Debug ]----------"
	@"$(MAKE)" -f  "QuadTree.mk"
clean:
	@echo "----------Cleaning project:[ QuadTree - Debug ]----------"
	@"$(MAKE)" -f  "QuadTree.mk" clean
