#ifndef VKH_HPP
#define VKH_HPP

#pragma once

#include <vector>
#include <vulkan/vulkan_raii.hpp>

struct VulkanResources {
    // TODO: update to c vulkan
    //  core
    static vk::raii::Context context;
    static vk::raii::Instance instance;
    static vk::raii::SurfaceKHR surface_khr;

    // devices
    static vk::raii::PhysicalDevice physical_device;
    static vk::raii::Device logical_device;

    // queue
    static vk::raii::Queue graphics_queue;
    static vk::raii::Queue present_queue;

    // surface config
    struct SurfaceConfig {
        vk::SurfaceCapabilitiesKHR capabilities;
        std::vector<vk::SurfaceFormatKHR> formats;
        std::vector<vk::PresentModeKHR> present_modes;

        vk::SurfaceFormatKHR chosen_format;
        vk::PresentModeKHR chosen_present_mode;
        vk::Extent2D chosen_extent;

        uint32_t image_count;
    };

    // swapchain
    static vk::raii::SwapchainKHR swapchain_khr;

    // shader module
    static vk::raii::ShaderModule shader_module;

    // pipeline
    static vk::raii::Pipeline graphics_pipeline;
    static vk::raii::PipelineLayout pipeline_layout;

    // layout
    static vk::raii::DescriptorSetLayout descriptor_set_layout;

    // command pool
    static vk::raii::CommandPool command_pool;

    // descriptor pool
    static vk::raii::DescriptorPool descriptor_pool;

    // validation layer
    static inline const std::vector<char const *> validation_layers = {
        "VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
    static constexpr bool enable_validation_layers = false;
#else
    static constexpr bool enable_validation_layers = true;
#endif
};

#endif // !VKH_HPP
